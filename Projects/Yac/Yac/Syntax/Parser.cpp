#include "Parser.h"

#include <Yac/Syntax/Lexer.h>
#include <Yac/Syntax/Expressions.h>
#include <Yac/Syntax/Statements.h>

using namespace Yac::Core;
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

const Token& Parser::consume() noexcept
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
	step();
	return t; // return consumed token
}

const Token& Parser::peek(UIntT offset) const noexcept
{
	UIntT index = _position + offset;
	
	// If trying to access a token that do not exists
	// return EoF
	if (index >= _tokens.size()) return _tokens.back();
	return _tokens[index];
}

bool Parser::match(TokenType type, UIntT offset) const noexcept { return peek(offset).getType() == type; }
bool Parser::matchNext(TokenType type) const noexcept { return next().getType() == type; }

const Token& Parser::matchAndConsume(TokenType type) noexcept
{
	const Token& t = consume();
	if (t.getType() != type)
		_errorList.reportUnexpectedToken(type, t.getType(), t.getSpan());
	return t;
}

Statement* Parser::Parse()
{
	Statement* statement = parseStatement();
	return statement;
}

Statement* Parser::parseStatement() noexcept
{
	switch (current().getType())
	{
		case TokenType::OpenBrackets: return parseBlockStatement();
		case TokenType::Keyword: return parseStatementKeyword();
		default: return parseExpressionStatement();
	}
}

Statement* Parser::parseBlockStatement() noexcept
{
	step(); // First token is Open Brackets

	std::vector<Statement*> _statements;
	while (current().getType() != TokenType::CloseBrackets)
	{
		// Error check: finding EoF when the block is not closed yet
		if (current().getType() == TokenType::EndOfFile)
		{
			_errorList.reportUnexpectedToken(TokenType::CloseBrackets, TokenType::EndOfFile, current().getSpan());
			return nullptr;
		}

		Statement* statement = parseStatement();
		_statements.push_back(statement);
	}

	step(); // Last token is Closed Brackets

	return new BlockStatement(_statements);
}

Statement* Parser::parseStatementKeyword() noexcept
{
	Keyword keyword = toKeyword(current().getText());
	switch (keyword)
	{
		case Keyword::Let: return parseVariableDeclaration();
		case Keyword::If: return parseIfStatement();
		case Keyword::While: return parseWhileStatement();
		case Keyword::For: return parseForStatement();
		default: return parseExpressionStatement();
	}
}

Statement* Parser::parseIfStatement() noexcept
{
	step(); // First token is 'if'

	matchAndConsume(TokenType::OpenParentheses);
	Expression* condition = parseConditional();
	matchAndConsume(TokenType::CloseParentheses);
	Statement* statement = parseStatement();

	const Token& currentToken = current();
	Statement* elseStatement = Statement::Null();
	if (currentToken.getType() == TokenType::Keyword && toKeyword(currentToken.getText()) == Keyword::Else)
	{
		step(); // Current token is 'else'
		elseStatement = parseStatement();
	}

	return new IfStatement(condition, statement, elseStatement);
}

Statement* Parser::parseForStatement() noexcept
{
	step(); // First token is 'for'

	matchAndConsume(TokenType::OpenParentheses);

	// Initial assignment is optional
	Expression* assignment = nullptr;
	if (!match(TokenType::Semicolon))
		assignment = parseConditional();
	matchAndConsume(TokenType::Semicolon);
	
	// Condition is optional
	Expression* condition = nullptr;
	if (!match(TokenType::Semicolon))
		condition = parseExpression();
	matchAndConsume(TokenType::Semicolon);

	// Update is optional
	Expression* update = parseExpression();
	matchAndConsume(TokenType::CloseParentheses);

	Statement* statement = parseStatement();

	return new ForStatement(assignment, condition, update, statement);
}

Statement* Parser::parseWhileStatement() noexcept
{
	step(); // First token is 'while'

	matchAndConsume(TokenType::OpenParentheses);
	Expression* condition = parseConditional();
	matchAndConsume(TokenType::CloseParentheses);

	Statement* statement = parseStatement();
	return new WhileStatement(condition, statement);
}

Statement* Parser::parseExpressionStatement() noexcept
{
	Expression* expression = parseInstruction();
	return new ExpressionStatement(expression);
}

Statement* Parser::parseVariableDeclaration(Keyword keyword) noexcept
{
	step(); // First token is the var decl keyword
	const Token& name = matchAndConsume(TokenType::Identifier);

	// Assignment is optional
	bool assign = match(TokenType::EqualSymbol);
	Expression* value = nullptr;
	if (assign)
	{
		step(); // Current token is 'equal'
		value = parseExpression();
	}
	matchAndConsume(TokenType::Semicolon);
	return new VariableDeclarationStatement(keyword, name.getText(), value);
}

Expression* Parser::parseInt(NumericBase base) noexcept
{
	const Token& t = consume();
	return new NumericLiteralExpression(t.getText(), NumericType::Int, base);
}

Expression* Parser::parseUInt(NumericBase base) noexcept
{
	const Token& t = consume();
	return new NumericLiteralExpression(t.getText(), NumericType::UInt, base);
}

Expression* Parser::parseFloat(NumericBase base) noexcept
{
	const Token& t = consume();
	return new NumericLiteralExpression(t.getText(), NumericType::Float, base);
}

Expression* Parser::parseDouble(NumericBase base) noexcept
{
	const Token& t = consume();
	return new NumericLiteralExpression(t.getText(), NumericType::Double, base);
}

Expression* Parser::parseBoolean() noexcept
{
	const Token& t = consume();
	Keyword keyword = toKeyword(t.getText());
	if (keyword != Keyword::True && keyword != Keyword::False) 
		_errorList.reportNotABooleanLiteral(t.getText(), t.getSpan());

	return new BooleanLiteralExpression(static_cast<bool>(keyword));
}

Expression* Parser::parseName() noexcept
{
	const Token& id = matchAndConsume(TokenType::Identifier);
	TokenType next = current().getType();
	Expression* expr = new IdentifierExpression(id.getText());
	switch (next)
	{
		case TokenType::DoublePlusSymbol: step(); return new UnaryOperationExpression(Operator::PostIncrement, expr);
		case TokenType::DoubleMinusSymbol: step(); return new UnaryOperationExpression(Operator::PostDecrement, expr);
		default: return expr;
	}
}

Expression* Parser::parseStringLiteral() noexcept
{
	std::string s = matchAndConsume(TokenType::StringLiteral).getText();
	s = s.substr(1, s.length() - 2);
	return new StringExpression(s);
}

Expression* Parser::parsePrefix() noexcept
{
	TokenType type = consume().getType();
	switch (type)
	{
		case TokenType::DoublePlusSymbol: return new UnaryOperationExpression(Operator::PreIncrement, parseName());
		case TokenType::DoubleMinusSymbol: return new UnaryOperationExpression(Operator::PreDecrement, parseName());
		default: return parseName();
	}
}

Expression* Parser::parseParentheses() noexcept
{
	step(); // Current token is 'Open Parenthesis'
	Expression* expression = parseExpression();
	matchAndConsume(TokenType::CloseParentheses);
	return new ParenthesesExpression(expression);
}

Expression* Parser::parseExpression() noexcept
{
	// Resolve assignments first
	AssignmentOperator op = toAssignmentOperator(next().getType());

	// If this token is an identifier and the next is an Assignment Operator
	// We are parsing an assignment expression
	if (match(TokenType::Identifier) && op != AssignmentOperator::Unknown) 
		return parseAssignmentExpression(op);

	// Elsewise we are parsing a math expression
	Expression* expression = parseMathExpression();

	if (!match(TokenType::QuestionMarkSymbol)) return expression;

	// If the next token is a Question Mark
	// We are probably trying to check an
	// inline if-else

	step(); // Current token is the Question Mark
	Expression* trueExpression = parseMathExpression();
	// We expect an alternative return value
	matchAndConsume(TokenType::Colon);
	Expression* falseExpression = parseMathExpression();

	return new InlineIfElseExpression(expression, trueExpression, falseExpression);
}

Expression* Parser::parseConditional() noexcept
{
	if (current().getText() != "let") return parseExpression();
	
	step(); // Current is token is 'let'
	const Token& name = matchAndConsume(TokenType::Identifier);
	matchAndConsume(TokenType::EqualSymbol);
	Expression* init = parseExpression();

	return new ConditionalDeclarationExpression(name.getText(), init);
}

Expression* Parser::parseFunctionCallOrName() noexcept
{
	if (next().getType() == TokenType::OpenParentheses)
		return parseFunctionCall();
	return parseName();
}

Expression* Parser::parseFunctionCall() noexcept
{
	// Identifier token
	const Token& funcName = consume();

	// Current token is open parenthesis
	step();

	std::vector<Expression*> arguments;
	while (true)
	{
		Expression* expression = parseExpression();
		arguments.push_back(expression);

		if (current().getType() == TokenType::Comma) step();
		else break;
	}

	matchAndConsume(TokenType::CloseParentheses);
	return new FunctionCallExpression(funcName.getText(), arguments);
}

Expression* Parser::parseInstruction() noexcept
{
	Expression* expression = parseExpression();
	matchAndConsume(TokenType::Semicolon);
	return expression;
}

Expression* Parser::parsePrimaryExpression() noexcept
{
	switch (current().getType())
	{
		case TokenType::Int: return parseInt();
		case TokenType::UInt: return parseUInt();
		case TokenType::Float: return parseFloat();
		case TokenType::Double: return parseDouble();

		case TokenType::BinaryUInt: return parseUInt(NumericBase::Binary);
		case TokenType::BinaryFloat: return parseFloat(NumericBase::Binary);
		case TokenType::BinaryDouble: return parseDouble(NumericBase::Binary);

		case TokenType::HexUInt: return parseUInt(NumericBase::Hex);
		case TokenType::HexFloat: return parseFloat(NumericBase::Hex);
		case TokenType::HexDouble: return parseDouble(NumericBase::Hex);

		case TokenType::OpenParentheses: return parseParentheses();
		case TokenType::Keyword: return parseBoolean();

		case TokenType::Identifier: return parseFunctionCallOrName();
		case TokenType::StringLiteral: return parseStringLiteral();
		default: return parsePrefix();
	}
}

Expression* Parser::parseAssignmentExpression(AssignmentOperator op) noexcept
{
	const Token& id = consume(); // Current token is the name of the variable
	step(); // Current token is the Assignment Operator
	Expression* expression = parseExpression();
	return new AssignmentExpression(id.getText(), op, expression);
}

Expression* Parser::parseMathExpression(UIntT parentPrecedence) noexcept
{
	// If the first token found is an Enclosing Token
	// There is no expression, instruction ends here
	switch (current().getType())
	{
		case TokenType::Semicolon:
		case TokenType::CloseParentheses:
		case TokenType::CloseSquared:
			return nullptr;
		default: break;
	}

	Expression* left = nullptr;

	Operator op = toUnaryOperator(current().getType());
	unsigned int precedence = getOperatorPrecedence(op);

	if (precedence && precedence >= parentPrecedence)
	{
		step(); // Current token is the operator
		Expression* operand = parseMathExpression(precedence);
		left = new UnaryOperationExpression(op, operand);
	}
	else left = parsePrimaryExpression();

	while (true)
	{
		op = toBinaryOperator(current().getType());
		precedence = getOperatorPrecedence(op);

		if (!precedence || precedence <= parentPrecedence) break;

		step(); // Current token is the left expression
		Expression* right = parseMathExpression(precedence);
		left = new BinaryOperationExpression(left, op, right);
	}

	return left;
}