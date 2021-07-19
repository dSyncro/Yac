#include "Binder.h"

using namespace Yac;

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
	}

	return nullptr;
}

BAssignmentExpression* Binder::bindAssignment(const AssignmentExpression* expression)
{
	BExpression* rvalue = bindExpression(expression->getExpression());
	return new BAssignmentExpression(expression->getIdentifier(), expression->getAssignmentOperator(), rvalue, Namespace::getGlobal());
}

BBinaryExpression* Binder::bindBinary(const BinaryOperationExpression* expression)
{
	BExpression* left = bindExpression(expression->getLeft());
	BExpression* right = bindExpression(expression->getRight());
	return new BBinaryExpression(left, expression->getOperator(), right);
}

BBooleanLiteralExpression* Binder::bindBooleanLiteral(const BooleanLiteralExpression* expression)
{
	return new BBooleanLiteralExpression(expression->getValue());
}

BConditionalDeclExpression* Binder::bindConditionalDeclaration(const ConditionalDeclarationExpression* expression)
{
	BExpression* initializer = bindExpression(expression->getInitializer());
	return new BConditionalDeclExpression(expression->getName(), initializer);
}

BIdentifierExpression* Binder::bindIdentifier(const IdentifierExpression* expression)
{
	return new BIdentifierExpression(expression->getIdentifier(), Namespace::getGlobal());
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
	return new BNumericLiteralExpression(expression->getNumeric(), expression->getNumericType());
}

BParenthesesExpression* Binder::bindParentheses(const ParenthesesExpression* expression)
{
	BExpression* parenthesesExpr = bindExpression(expression->getExpression());
	return new BParenthesesExpression(parenthesesExpr);
}

BStringLiteralExpression* Binder::bindStringLiteral(const StringLiteralExpression* expression)
{
	return new BStringLiteralExpression(expression->getText());
}

BUnaryExpression* Binder::bindUnary(const UnaryOperationExpression* expression)
{
	BExpression* operand = bindExpression(expression->getOperand());
	return new BUnaryExpression(expression->getOperator(), operand);
}
