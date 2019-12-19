#include "Parser.h"

#include <yac/Syntax/Lexer/Lexer.h>
#include <yac/Syntax/SyntaxRules.h>

#include <yac/Syntax/Expressions/Expressions.h>
#include <yac/Syntax/Statements/Statements.h>

using namespace Yac::Syntax;
using namespace Yac::Errors;

Parser::Parser(std::string source)
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

const Token& Parser::ConsumeNext() noexcept
{
	if (_position >= _tokens.size()) 
	{ 
		const Token& t = EndOfFile();
		_reporter.ReportUnexpectedToken(TokenType::Semicolon, TokenType::EndOfFile, t.span());
		return t;
	}
	Token& t = _tokens[_position];
	Step();
	return t;
}

const Token& Parser::Peek(unsigned int offset) const noexcept
{
	unsigned int index = _position + offset;
	if (index >= _tokens.size()) return EndOfFile();
	return _tokens[index];
}

bool Parser::Match(TokenType type, unsigned int offset) const noexcept { return Peek(offset).type() == type; }
bool Parser::MatchNext(TokenType type) const noexcept { return Next().type() == type; }

const Token& Parser::EndOfFile() const noexcept { return _tokens[_tokens.size() - 1]; }
const Token& Parser::MatchAndConsume(TokenType type) noexcept
{
	const Token& t = ConsumeNext();
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
	Step();

	std::vector<Statement*> _statements;
	while (Current().type() != TokenType::CloseBrackets && Current().type() != TokenType::EndOfFile)
	{
		Statement* statement = ParseStatement();
		_statements.push_back(statement);
	}

	Step();

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
	// If
	Step();

	

	MatchAndConsume(TokenType::OpenParentheses);
	Expression* condition = ParseConditional();
	MatchAndConsume(TokenType::CloseParentheses);
	Statement* statement = ParseStatement();

	// Else
	const Token& current = Current();
	Statement* elseStatement = Statement::Null();
	if (current.type() == TokenType::Keyword && ToKeyword(current.text()) == Keyword::Else)
	{
		Step();
		elseStatement = ParseStatement();
	}

	return new IfStatement(condition, statement, elseStatement);
}

Statement* Parser::ParseForStatement() noexcept
{
	Step();

	MatchAndConsume(TokenType::OpenParentheses);

	Expression* assignment = nullptr;
	if (!Match(TokenType::Semicolon))
	{
		assignment = ParseConditional();
		MatchAndConsume(TokenType::Semicolon);
	}
	else Step();
	
	Expression* condition = nullptr;
	if (!Match(TokenType::Semicolon))
	{
		condition = ParseExpression();
		MatchAndConsume(TokenType::Semicolon);
	}
	else Step();

	Expression* update = ParseExpression();

	MatchAndConsume(TokenType::CloseParentheses);

	Statement* statement = ParseStatement();

	return new ForStatement(assignment, condition, update, statement);
}

Statement* Parser::ParseWhileStatement() noexcept
{
	Step();

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
	Step();
	const Token& name = MatchAndConsume(TokenType::Identifier);
	bool assign = Match(TokenType::EqualSymbol);
	Expression* value = Expression::Null();
	if (assign)
	{
		Step();
		value = ParseExpression();
	}
	MatchAndConsume(TokenType::Semicolon);
	return new VariableDeclaration(keyword, name.text(), value);
}

Expression* Parser::ParseInt(NumericBase base) noexcept
{
	const Token& t = ConsumeNext();
	return new NumericLiteral(t.text(), NumericType::Int, base);
}

Expression* Parser::ParseUInt(NumericBase base) noexcept
{
	const Token& t = ConsumeNext();
	return new NumericLiteral(t.text(), NumericType::UInt, base);
}

Expression* Parser::ParseFloat(NumericBase base) noexcept
{
	const Token& t = ConsumeNext();
	return new NumericLiteral(t.text(), NumericType::Float, base);
}

Expression* Parser::ParseDouble(NumericBase base) noexcept
{
	const Token& t = ConsumeNext();
	return new NumericLiteral(t.text(), NumericType::Double, base);
}

Expression* Parser::ParseBoolean() noexcept
{
	const Token& t = ConsumeNext();
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
	TokenType type = ConsumeNext().type();
	switch (type)
	{
		case TokenType::DoublePlusSymbol: return new UnaryOperation(Operator::PreIncrement, ParseIdentifier());
		case TokenType::DoubleMinusSymbol: return new UnaryOperation(Operator::PreDecrement, ParseIdentifier());
		default: return ParseIdentifier();
	}
}

Expression* Parser::ParseParentheses() noexcept
{
	Step();
	Expression* expression = ParseExpression();
	MatchAndConsume(TokenType::CloseParentheses);
	return new ParenthesesExpression(expression);
}

Expression* Parser::ParseExpression() noexcept
{
	AssignmentOperator op = ToAssignmentOperator(Next().type());
	return Match(TokenType::Identifier) && op != AssignmentOperator::Unknown ?
		ParseAssignmentExpression(op) :
		ParseMathExpression();
}

Expression* Parser::ParseConditional() noexcept
{
	if (Current().text() != "let") return ParseExpression();
	
	Step();
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
	const Token& id = ConsumeNext();
	Step();
	Expression* expression = ParseExpression();
	return new AssignmentExpression(id.text(), op, expression);
}

Expression* Parser::ParseMathExpression(unsigned int parentPrecedence) noexcept
{
	if (Current().type() == TokenType::Semicolon) return nullptr;

	Expression* left = nullptr;

	Operator op = ToUnaryOperator(Current().type());
	unsigned int precedence = (unsigned int)op;

	if (precedence && precedence >= parentPrecedence)
	{
		Step();
		Expression* operand = ParseMathExpression(precedence);
		left = new UnaryOperation(op, operand);
	}
	else left = ParsePrimaryExpression();

	while (true)
	{
		op = ToBinaryOperator(Current().type());
		precedence = (unsigned int)op;

		if (!precedence || precedence <= parentPrecedence) break;

		Step();
		Expression* right = ParseMathExpression(precedence);
		left = new BinaryOperation(left, op, right);
	}

	return left;
}