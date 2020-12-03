#include "Parser.h"

#include <Syntax/Lexer/Lexer.h>
#include <Syntax/SyntaxRules.h>

#include <Syntax/Expressions/Expressions.h>
#include <Syntax/Statements/Statements.h>

using namespace Yac::Text;
using namespace Yac::Syntax;
using namespace Yac::Errors;

Parser::Parser(const SourceText& source, ErrorList& errorList) : _errorList(errorList)
{
	Lexer lexer = Lexer(source, errorList);
	Token t;
	do
	{
		t = lexer.consumeNext();
		if (t.getType() != TokenType::Whitespace && t.getType() != TokenType::Newline) 
			_tokens.push_back(t);
	} while (t.getType() != TokenType::EndOfFile);
}

const Token& Parser::Consume() noexcept
{
	// Error check: trying to consume unexisting token
	if (_position >= _tokens.size()) 
	{
		const Token& t = _tokens.back(); // Get EoF
		_errorList.reportUnexpectedToken(TokenType::Semicolon, TokenType::EndOfFile, t.getSpan());
		return t; // return EoF
	}

	// Consume
	Token& t = _tokens[_position];
	Step();
	return t; // return consumed token
}

const Token& Parser::Peek(std::size_t offset) const noexcept
{
	std::size_t index = _position + offset;
	
	// If trying to access a token that do not exists
	// return EoF
	if (index >= _tokens.size()) return _tokens.back();
	return _tokens[index];
}

bool Parser::Match(TokenType type, std::size_t offset) const noexcept { return Peek(offset).getType() == type; }
bool Parser::MatchNext(TokenType type) const noexcept { return Next().getType() == type; }

const Token& Parser::MatchAndConsume(TokenType type) noexcept
{
	const Token& t = Consume();
	if (t.getType() != type)
		_errorList.reportUnexpectedToken(type, t.getType(), t.getSpan());
	return t;
}

Statement* Parser::Parse()
{
	Statement* statement = ParseStatement();
	return statement;
}

Statement* Parser::ParseStatement() noexcept
{
	switch (Current().getType())
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
	while (Current().getType() != TokenType::CloseBrackets)
	{
		// Error check: finding EoF when the block is not closed yet
		if (Current().getType() == TokenType::EndOfFile)
		{
			_errorList.reportUnexpectedToken(TokenType::CloseBrackets, TokenType::EndOfFile, Current().getSpan());
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
	Keyword keyword = toKeyword(Current().getText());
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
	if (current.getType() == TokenType::Keyword && toKeyword(current.getText()) == Keyword::Else)
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
	Expression* value = nullptr;
	if (assign)
	{
		Step(); // Current token is 'equal'
		value = ParseExpression();
	}
	MatchAndConsume(TokenType::Semicolon);
	return new VariableDeclaration(keyword, name.getText(), value);
}

Expression* Parser::ParseInt(NumericBase base) noexcept
{
	const Token& t = Consume();
	return new NumericLiteral(t.getText(), NumericType::Int, base);
}

Expression* Parser::ParseUInt(NumericBase base) noexcept
{
	const Token& t = Consume();
	return new NumericLiteral(t.getText(), NumericType::UInt, base);
}

Expression* Parser::ParseFloat(NumericBase base) noexcept
{
	const Token& t = Consume();
	return new NumericLiteral(t.getText(), NumericType::Float, base);
}

Expression* Parser::ParseDouble(NumericBase base) noexcept
{
	const Token& t = Consume();
	return new NumericLiteral(t.getText(), NumericType::Double, base);
}

Expression* Parser::ParseBoolean() noexcept
{
	const Token& t = Consume();
	Keyword keyword = Keyword::Unknown;

	if (t.getText() == "true") keyword = Keyword::True;
	else if (t.getText() == "false") keyword = Keyword::False;
	else _errorList.reportNotABooleanLiteral(t.getText(), t.getSpan());

	return new BooleanLiteral((bool)keyword);
}

Expression* Parser::ParseIdentifier() noexcept
{
	const Token& id = MatchAndConsume(TokenType::Identifier);
	TokenType next = Current().getType();
	Expression* expr = new IdentifierExpression(id.getText());
	switch (next)
	{
		case TokenType::DoublePlusSymbol: Step(); return new UnaryOperation(Operator::PostIncrement, expr);
		case TokenType::DoubleMinusSymbol: Step(); return new UnaryOperation(Operator::PostDecrement, expr);
		default: return expr;
	}
}

Expression* Parser::ParseStringLiteral() noexcept
{
	std::string s = MatchAndConsume(TokenType::StringLiteral).getText();
	s = s.substr(1, s.length() - 2);
	return new StringExpression(s);
}

Expression* Parser::ParsePrefix() noexcept
{
	TokenType type = Consume().getType();
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
	AssignmentOperator op = toAssignmentOperator(Next().getType());

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
	if (Current().getText() != "let") return ParseExpression();
	
	Step(); // Current is token is 'let'
	const Token& name = MatchAndConsume(TokenType::Identifier);
	MatchAndConsume(TokenType::EqualSymbol);
	Expression* init = ParseExpression();

	return new ConditionalDeclaration(name.getText(), init);
}

Expression* Parser::ParseInstruction() noexcept
{
	Expression* expression = ParseExpression();
	MatchAndConsume(TokenType::Semicolon);
	return expression;
}

Expression* Parser::ParsePrimaryExpression() noexcept
{
	switch (Current().getType())
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
		case TokenType::StringLiteral: return ParseStringLiteral();
		default: return ParsePrefix();
	}
}

Expression* Parser::ParseAssignmentExpression(AssignmentOperator op) noexcept
{
	const Token& id = Consume(); // Current token is the name of the variable
	Step(); // Current token is the Assignment Operator
	Expression* expression = ParseExpression();
	return new AssignmentExpression(id.getText(), op, expression);
}

Expression* Parser::ParseMathExpression(unsigned int parentPrecedence) noexcept
{
	// If the first token found is an Enclosing Token
	// There is no expression, instruction ends here
	switch (Current().getType())
	{
		case TokenType::Semicolon:
		case TokenType::CloseParentheses:
		case TokenType::CloseSquared:
			return nullptr;
		default: break;
	}

	Expression* left = nullptr;

	Operator op = toUnaryOperator(Current().getType());
	unsigned int precedence = getOperatorPrecedence(op);

	if (precedence && precedence >= parentPrecedence)
	{
		Step(); // Current token is the operator
		Expression* operand = ParseMathExpression(precedence);
		left = new UnaryOperation(op, operand);
	}
	else left = ParsePrimaryExpression();

	while (true)
	{
		op = toBinaryOperator(Current().getType());
		precedence = getOperatorPrecedence(op);

		if (!precedence || precedence <= parentPrecedence) break;

		Step(); // Current token is the left expression
		Expression* right = ParseMathExpression(precedence);
		left = new BinaryOperation(left, op, right);
	}

	return left;
}