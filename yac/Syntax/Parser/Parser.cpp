#include "Parser.h"

#include <yac/Syntax/Lexer/Lexer.h>
#include <yac/Syntax/SyntaxRules.h>

#include <yac/Syntax/Expressions/Expressions.h>
#include <yac/Syntax/Statements/Statements.h>

using namespace Yac::Text;
using namespace Yac::Syntax;
using namespace Yac::Errors;

Parser::Parser(SourceText source)
{
	Lexer lexer = Lexer(source);
	Token t;
	do
	{
		t = lexer.Lex();
		if (t.type() != TokenType::Whitespace && t.type() != TokenType::Newline) 
			_tokens.push_back(t);
	} while (t.type() != TokenType::EndOfFile);
}

const Token& Parser::Consume() noexcept
{
	// Error check: trying to consume unexisting token
	if (_position >= _tokens.size()) 
	{
		const Token& t = _tokens.back(); // Get EoF
		_reporter.ReportUnexpectedToken(TokenType::Semicolon, TokenType::EndOfFile, t.span());
		return t; // return EoF
	}

	// Consume
	Token& t = _tokens[_position];
	Step();
	return t; // return consumed token
}

const Token& Parser::Peek(unsigned int offset) const noexcept
{
	unsigned int index = _position + offset;
	
	// If trying to access a token that do not exists
	// return EoF
	if (index >= _tokens.size()) return _tokens.back();
	return _tokens[index];
}

bool Parser::Match(TokenType type, unsigned int offset) const noexcept { return Peek(offset).type() == type; }
bool Parser::MatchNext(TokenType type) const noexcept { return Next().type() == type; }

const Token& Parser::MatchAndConsume(TokenType type) noexcept
{
	const Token& t = Consume();
	if (t.type() != type)
		_reporter.ReportUnexpectedToken(type, t.type(), t.span());
	return t;
}

Statement* Parser::Parse()
{
	Statement* statement = ParseStatement();
	return statement;
}

Statement* Parser::ParseStatement() noexcept
{
	switch (Current().type())
	{
		case TokenType::OpenBrackets: return ParseBlockStatement();
		case TokenType::Keyword: return ParseStatementKeyword();
		default: return ParseInstructionStatement();
	}
}

Statement* Parser::ParseBlockStatement() noexcept
{
	Step(); // First token is Open Brackets

	std::vector<Statement*> _statements;
	while (Current().type() != TokenType::CloseBrackets)
	{
		// Error check: finding EoF when the block is not closed yet
		if (Current().type() == TokenType::EndOfFile)
		{
			_reporter.ReportUnexpectedToken(TokenType::CloseBrackets, TokenType::EndOfFile, Current().span());
			return nullptr;
		}

		Statement* statement = ParseStatement();
		_statements.push_back(statement);
	}

	Step(); // Last token is Closed Brackets

	return new BlockStatement(_statements);
}

Statement* Parser::ParseStatementKeyword() noexcept
{
	Keyword keyword = ToKeyword(Current().text());
	switch (keyword)
	{
		case Keyword::Let: return ParseVariableDeclaration();
		case Keyword::If: return ParseIfStatement();
		case Keyword::While: return ParseWhileStatement();
		case Keyword::For: return ParseForStatement();
		default: return ParseInstructionStatement();
	}
}

Statement* Parser::ParseIfStatement() noexcept
{
	Step(); // First token is 'if'

	MatchAndConsume(TokenType::OpenParentheses);
	Expression* condition = ParseConditional();
	MatchAndConsume(TokenType::CloseParentheses);
	Statement* statement = ParseStatement();

	const Token& current = Current();
	Statement* elseStatement = Statement::Null();
	if (current.type() == TokenType::Keyword && ToKeyword(current.text()) == Keyword::Else)
	{
		Step(); // Current token is 'else'
		elseStatement = ParseStatement();
	}

	return new IfStatement(condition, statement, elseStatement);
}

Statement* Parser::ParseForStatement() noexcept
{
	Step(); // First token is 'for'

	MatchAndConsume(TokenType::OpenParentheses);

	// Initial assignment is optional
	Expression* assignment = nullptr;
	if (!Match(TokenType::Semicolon))
		assignment = ParseConditional();
	MatchAndConsume(TokenType::Semicolon);
	
	// Condition is optional
	Expression* condition = nullptr;
	if (!Match(TokenType::Semicolon))
		condition = ParseExpression();
	MatchAndConsume(TokenType::Semicolon);

	// Update is optional
	Expression* update = ParseExpression();
	MatchAndConsume(TokenType::CloseParentheses);

	Statement* statement = ParseStatement();

	return new ForStatement(assignment, condition, update, statement);
}

Statement* Parser::ParseWhileStatement() noexcept
{
	Step(); // First token is 'while'

	MatchAndConsume(TokenType::OpenParentheses);
	Expression* condition = ParseConditional();
	MatchAndConsume(TokenType::CloseParentheses);

	Statement* statement = ParseStatement();
	return new WhileStatement(condition, statement);
}

Statement* Parser::ParseInstructionStatement() noexcept
{
	Expression* expression = ParseInstruction();
	return new ExpressionStatement(expression);
}

Statement* Parser::ParseVariableDeclaration(Keyword keyword) noexcept
{
	Step(); // First token is the var decl keyword
	const Token& name = MatchAndConsume(TokenType::Identifier);

	// Assignment is optional
	bool assign = Match(TokenType::EqualSymbol);
	Expression* value = Expression::Null();
	if (assign)
	{
		Step(); // Current token is 'equal'
		value = ParseExpression();
	}
	MatchAndConsume(TokenType::Semicolon);
	return new VariableDeclaration(keyword, name.text(), value);
}

Expression* Parser::ParseInt(NumericBase base) noexcept
{
	const Token& t = Consume();
	return new NumericLiteral(t.text(), NumericType::Int, base);
}

Expression* Parser::ParseUInt(NumericBase base) noexcept
{
	const Token& t = Consume();
	return new NumericLiteral(t.text(), NumericType::UInt, base);
}

Expression* Parser::ParseFloat(NumericBase base) noexcept
{
	const Token& t = Consume();
	return new NumericLiteral(t.text(), NumericType::Float, base);
}

Expression* Parser::ParseDouble(NumericBase base) noexcept
{
	const Token& t = Consume();
	return new NumericLiteral(t.text(), NumericType::Double, base);
}

Expression* Parser::ParseBoolean() noexcept
{
	const Token& t = Consume();
	Keyword keyword = Keyword::Unknown;

	if (t.text() == "true") keyword = Keyword::True;
	else if (t.text() == "false") keyword = Keyword::False;
	else _reporter.ReportNotABooleanLiteral(t.text(), t.span());

	return new BooleanLiteral((bool)keyword);
}

Expression* Parser::ParseIdentifier() noexcept
{
	const Token& id = MatchAndConsume(TokenType::Identifier);
	TokenType next = Current().type();
	Expression* expr = new IdentifierExpression(id.text());
	switch (next)
	{
		case TokenType::DoublePlusSymbol: Step(); return new UnaryOperation(Operator::PostIncrement, expr);
		case TokenType::DoubleMinusSymbol: Step(); return new UnaryOperation(Operator::PostDecrement, expr);
		default: return expr;
	}
}

Expression* Parser::ParsePrefix() noexcept
{
	TokenType type = Consume().type();
	switch (type)
	{
		case TokenType::DoublePlusSymbol: return new UnaryOperation(Operator::PreIncrement, ParseIdentifier());
		case TokenType::DoubleMinusSymbol: return new UnaryOperation(Operator::PreDecrement, ParseIdentifier());
		default: return ParseIdentifier();
	}
}

Expression* Parser::ParseParentheses() noexcept
{
	Step(); // Current token is 'Open Parenthesis'
	Expression* expression = ParseExpression();
	MatchAndConsume(TokenType::CloseParentheses);
	return new ParenthesesExpression(expression);
}

Expression* Parser::ParseExpression() noexcept
{
	// Resolve assignments first
	AssignmentOperator op = ToAssignmentOperator(Next().type());

	// If this token is an identifier and the next is an Assignment Operator
	// We are parsing an assignment expression
	if (Match(TokenType::Identifier) && op != AssignmentOperator::Unknown) return ParseAssignmentExpression(op);

	// Elsewise we are parsing a math expression
	Expression* expression = ParseMathExpression();

	if (!Match(TokenType::QuestionMark)) return expression;

	// If the next token is a Question Mark
	// We are probably trying to check an
	// inline if-else

	Step(); // Current token is the Question Mark
	Expression* trueExpression = ParseMathExpression();
	// We expect an alternative return value
	MatchAndConsume(TokenType::Colon);
	Expression* falseExpression = ParseMathExpression();

	return new InlineIfElse(expression, trueExpression, falseExpression);
}

Expression* Parser::ParseConditional() noexcept
{
	if (Current().text() != "let") return ParseExpression();
	
	Step(); // Current is token is 'let'
	const Token& name = MatchAndConsume(TokenType::Identifier);
	MatchAndConsume(TokenType::EqualSymbol);
	Expression* init = ParseExpression();

	return new ConditionalDeclaration(name.text(), init);
}

Expression* Parser::ParseInstruction() noexcept
{
	Expression* expression = ParseExpression();
	MatchAndConsume(TokenType::Semicolon);
	return expression;
}

Expression* Parser::ParsePrimaryExpression() noexcept
{
	switch (Current().type())
	{
		case TokenType::Int: return ParseInt();
		case TokenType::UInt: return ParseUInt();
		case TokenType::Float: return ParseFloat();
		case TokenType::Double: return ParseDouble();

		case TokenType::BinaryUInt: return ParseUInt(NumericBase::Binary);
		case TokenType::BinaryFloat: return ParseFloat(NumericBase::Binary);
		case TokenType::BinaryDouble: return ParseDouble(NumericBase::Binary);

		case TokenType::HexUInt: return ParseUInt(NumericBase::Hex);
		case TokenType::HexFloat: return ParseFloat(NumericBase::Hex);
		case TokenType::HexDouble: return ParseDouble(NumericBase::Hex);

		case TokenType::OpenParentheses: return ParseParentheses();
		case TokenType::Keyword: return ParseBoolean();

		case TokenType::Identifier: return ParseIdentifier();
		default: return ParsePrefix();
	}
}

Expression* Parser::ParseAssignmentExpression(AssignmentOperator op) noexcept
{
	const Token& id = Consume(); // Current token is the name of the variable
	Step(); // Current token is the Assignment Operator
	Expression* expression = ParseExpression();
	return new AssignmentExpression(id.text(), op, expression);
}

Expression* Parser::ParseMathExpression(unsigned int parentPrecedence) noexcept
{
	// If the first token found is an Enclosing Token
	// There is no expression, instruction ends here
	switch (Current().type())
	{
		case TokenType::Semicolon:
		case TokenType::CloseParentheses:
		case TokenType::CloseSquared:
			return nullptr;
		default: break;
	}

	Expression* left = nullptr;

	Operator op = ToUnaryOperator(Current().type());
	unsigned int precedence = GetOperatorPrecedence(op);

	if (precedence && precedence >= parentPrecedence)
	{
		Step(); // Current token is the operator
		Expression* operand = ParseMathExpression(precedence);
		left = new UnaryOperation(op, operand);
	}
	else left = ParsePrimaryExpression();

	while (true)
	{
		op = ToBinaryOperator(Current().type());
		precedence = GetOperatorPrecedence(op);

		if (!precedence || precedence <= parentPrecedence) break;

		Step(); // Current token is the left expression
		Expression* right = ParseMathExpression(precedence);
		left = new BinaryOperation(left, op, right);
	}

	return left;
}