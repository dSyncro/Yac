#include "Binder.h"

using namespace Yac;

Binder::Binder()
	: _globalScope(new NamespaceScope())
{
	declareBuiltinTypes(_globalScope);
	declareBuiltinBinaryOperators(_globalScope);

	_currentScope = _globalScope;
}

Binder::~Binder()
{
	delete _globalScope;
}

BSyntaxTree Binder::bind(const SyntaxTree& tree)
{
	return bindStatement(tree.getRoot());
}

BStatement* Binder::bindStatement(const Statement* statement)
{
	switch (statement->getType())
	{
		case StatementType::Block:
			return bindBlockStatement(reinterpret_cast<const BlockStatement*>(statement));
		case StatementType::Expression:
			return bindExpressionStatement(reinterpret_cast<const ExpressionStatement*>(statement));
		case StatementType::For:
			return bindForStatement(reinterpret_cast<const ForStatement*>(statement));
		case StatementType::If:
			return bindIfStatement(reinterpret_cast<const IfStatement*>(statement));
		case StatementType::VariableDeclaration:
			return bindVarDeclStatement(reinterpret_cast<const VariableDeclarationStatement*>(statement));
		case StatementType::While:
			return bindWhileStatement(reinterpret_cast<const WhileStatement*>(statement));
		default:
			return nullptr;
	}
}

BStatement* Binder::bindBlockStatement(const BlockStatement* statement)
{
	std::vector<BStatement*> bStatements;
	bStatements.reserve(statement->getStatements().size());

	_currentScope = new BlockScope(_currentScope);

	for (const Statement* s : statement->getStatements())
		bStatements.push_back(bindStatement(s));

	BBlockStatement* out = new BBlockStatement(bStatements, reinterpret_cast<BlockScope*>(_currentScope));

	_currentScope = _currentScope->getParent();

	return out;
}

BStatement* Binder::bindExpressionStatement(const ExpressionStatement* statement)
{
	BExpression* expression = bindExpression(statement->getExpression());
	return new BExpressionStatement(expression, _currentScope);
}

BStatement* Binder::bindForStatement(const ForStatement* statement)
{
	_currentScope = new BlockScope(_currentScope);

	BExpression* assignment = bindExpression(statement->getAssignment());
	BExpression* condition = bindExpression(statement->getCondition());
	BExpression* update = bindExpression(statement->getUpdate());

	BStatement* forStatement = bindStatement(statement->getStatement());

	BForStatement* out = new BForStatement(assignment, condition, update, forStatement, reinterpret_cast<BlockScope*>(_currentScope));

	_currentScope = _currentScope->getParent();

	return out;
}

BStatement* Binder::bindIfStatement(const IfStatement* statement)
{
	_currentScope = new BlockScope(_currentScope);

	BExpression* condition = bindExpression(statement->getCondition());
	BStatement* ifStatement = bindStatement(statement->getStatement());
	BStatement* elseStatement = statement->isElseStatementPresent() ? bindStatement(statement->getElseStatement()) : nullptr;

	BIfStatement* out = new BIfStatement(condition, ifStatement, elseStatement, reinterpret_cast<BlockScope*>(_currentScope));

	_currentScope = _currentScope->getParent();

	return out;
}

BStatement* Binder::bindVarDeclStatement(const VariableDeclarationStatement* statement)
{
	Keyword keyword = statement->getKeyword();
	const std::string& name = statement->getName();
	BExpression* init = bindExpression(statement->getInitializer());

	return new BVarDeclStatement(keyword, name, init, _currentScope);
}

BStatement* Binder::bindWhileStatement(const WhileStatement* statement)
{
	_currentScope = new BlockScope(_currentScope);

	BExpression* condition = bindExpression(statement->getCondition());
	BStatement* bStatement = bindStatement(statement->getStatement());

	BWhileStatement* out = new BWhileStatement(condition, bStatement, reinterpret_cast<BlockScope*>(_currentScope));

	_currentScope = _currentScope->getParent();

	return out;
}

BExpression* Binder::bindExpression(const Expression* expression)
{
	switch (expression->getType())
	{
		case ExpressionType::Assignment:
			return bindAssignment(reinterpret_cast<const AssignmentExpression*>(expression));
		case ExpressionType::BinaryOperation:
			return bindBinary(reinterpret_cast<const BinaryOperationExpression*>(expression));
		case ExpressionType::BooleanLiteral:
			return bindBooleanLiteral(reinterpret_cast<const BooleanLiteralExpression*>(expression));
		case ExpressionType::ConditionalDeclaration:
			return bindConditionalDeclaration(reinterpret_cast<const ConditionalDeclarationExpression*>(expression));
		// TODO:
		/*case ExpressionType::FunctionCall:
			return bindFunctionCall(reinterpret_cast<const FunctionCallExpression*>(expression));*/
		case ExpressionType::Identifier:
			return bindIdentifier(reinterpret_cast<const IdentifierExpression*>(expression));
		case ExpressionType::InlineIfElse:
			return bindInlineIfElse(reinterpret_cast<const InlineIfElseExpression*>(expression));
		case ExpressionType::NumericLiteral:
			return bindNumericLiteral(reinterpret_cast<const NumericLiteralExpression*>(expression));
		case ExpressionType::Parentheses:
			return bindParentheses(reinterpret_cast<const ParenthesesExpression*>(expression));
		case ExpressionType::StringLiteral:
			return bindStringLiteral(reinterpret_cast<const StringLiteralExpression*>(expression));
		case ExpressionType::UnaryOperation:
			return bindUnary(reinterpret_cast<const UnaryOperationExpression*>(expression));
		default: return nullptr;
	}
}

BAssignmentExpression* Binder::bindAssignment(const AssignmentExpression* expression)
{
	BExpression* rvalue = bindExpression(expression->getExpression());
	return new BAssignmentExpression(expression->getIdentifier(), expression->getAssignmentOperator(), rvalue, _currentScope);
}

BBinaryExpression* Binder::bindBinary(const BinaryOperationExpression* expression)
{
	BExpression* left = bindExpression(expression->getLeft());
	BExpression* right = bindExpression(expression->getRight());
	return new BBinaryExpression(left, expression->getOperator(), right, _currentScope);
}

BBooleanLiteralExpression* Binder::bindBooleanLiteral(const BooleanLiteralExpression* expression)
{
	return new BBooleanLiteralExpression(expression->getValue(), _currentScope);
}

BConditionalDeclExpression* Binder::bindConditionalDeclaration(const ConditionalDeclarationExpression* expression)
{
	BExpression* initializer = bindExpression(expression->getInitializer());
	return new BConditionalDeclExpression(expression->getName(), initializer);
}

BIdentifierExpression* Binder::bindIdentifier(const IdentifierExpression* expression)
{
	return new BIdentifierExpression(expression->getIdentifier(), _currentScope);
}

BInlineIfElse* Binder::bindInlineIfElse(const InlineIfElseExpression* expression)
{
	BExpression* condition = bindExpression(expression->getCondition());
	BExpression* ifTrue = bindExpression(expression->getTrueExpression());
	BExpression* ifFalse = bindExpression(expression->getFalseExpression());

	return new BInlineIfElse(condition, ifTrue, ifFalse);
}
BNumericLiteralExpression* Binder::bindNumericLiteral(const NumericLiteralExpression* expression)
{
	return new BNumericLiteralExpression(expression->getNumeric(), expression->getNumericType(), _currentScope);
}

BParenthesesExpression* Binder::bindParentheses(const ParenthesesExpression* expression)
{
	BExpression* parenthesesExpr = bindExpression(expression->getExpression());
	return new BParenthesesExpression(parenthesesExpr);
}

BStringLiteralExpression* Binder::bindStringLiteral(const StringLiteralExpression* expression)
{
	return new BStringLiteralExpression(expression->getText(), _currentScope);
}

BUnaryExpression* Binder::bindUnary(const UnaryOperationExpression* expression)
{
	BExpression* operand = bindExpression(expression->getOperand());
	return new BUnaryExpression(expression->getOperator(), operand);
}
