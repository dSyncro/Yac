#include "Binder.h"

using namespace Yac;

BExpression* Binder::bindExpression(const Expression* expression)
{
	/*switch (expression->getType())
	{
		case ExpressionType::Assignment:
			return bindAssignment(reinterpret_cast<const AssignmentExpression*>(expression));
		case ExpressionType::BinaryOperation:
			return bindBinary(reinterpret_cast<const BinaryOperationExpression*>(expression));
		case ExpressionType::BooleanLiteral:
			return bindBooleanLiteral(reinterpret_cast<const BooleanLiteralExpression*>(expression));
		case ExpressionType::ConditionalDeclaration:
			return bindConditionalDeclaration(reinterpret_cast<const ConditionalDeclarationExpression*>(expression));
		case ExpressionType::FunctionCall:
			return bindFunctionCall(reinterpret_cast<const FunctionCallExpression*>(expression));
		case ExpressionType::Identifier:
			return bindIdentifier(reinterpret_cast<const IdentifierExpression*>(expression));
		case ExpressionType::InlineIfElse:
			return bindInlineIfElse(reinterpret_cast<const InlineIfElseExpression*>(expression));
		case ExpressionType::NumericLiteral:
			return bindNumericLiteral(reinterpret_cast<const NumericLiteralExpression*>(expression));
		case ExpressionType::Parentheses:
			return bindParenthesis(reinterpret_cast<const ParenthesesExpression*>(expression));
		case ExpressionType::StringLiteral:
			return bindStringLiteral(reinterpret_cast<const StringLiteralExpression*>(expression));
		case ExpressionType::UnaryOperation:
			return bindUnaryOperation(reinterpret_cast<const UnaryOperationExpression*>(expression));
	}*/

	return nullptr;
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

BIdentifierExpression* Binder::bindIdentifier(const IdentifierExpression* expression)
{
	return new BIdentifierExpression(expression->getIdentifier(), Namespace::getGlobal());
}

BStringLiteralExpression* Binder::bindStringLiteral(const StringLiteralExpression* expression)
{
	return new BStringLiteralExpression(expression->getText());
}