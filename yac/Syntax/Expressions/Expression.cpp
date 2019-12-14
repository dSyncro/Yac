#include "Expression.h"

#include "Expressions.h"

using namespace Yac::Syntax;

void Expression::Dispose(Expression* expression)
{
    if (!expression) return;

	switch (expression->type())
	{
        case ExpressionType::NumericLiteral: delete (NumericLiteral*)expression; return;
        case ExpressionType::BooleanLiteral: delete (BooleanLiteral*)expression; return;
        case ExpressionType::IdentifierExpression: delete (IdentifierExpression*)expression; return;
        case ExpressionType::AssignmentExpression: delete (AssignmentExpression*)expression; return;
        case ExpressionType::ParenthesesExpression: delete (ParenthesesExpression*)expression; return;
        case ExpressionType::UnaryOperation: delete (UnaryOperation*)expression; return;
        case ExpressionType::BinaryOperation: delete (BinaryOperation*)expression; return;
        case ExpressionType::None: default: return;
	}
}

Expression* Expression::Null() noexcept { return nullptr; }