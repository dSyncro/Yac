#include "Expression.h"

#include "IdentifierExpression.h"
#include "Numeric/NumericLiteral.h"
#include "Operations/Operations.h"

using namespace Yac::Syntax;

void Expression::Dispose(Expression* expression)
{
    if (!expression) return;

	switch (expression->type())
	{
        case ExpressionType::NumericLiteral: delete (NumericLiteral*)expression; return;
        case ExpressionType::IdentifierExpression: delete (IdentifierExpression*)expression; return;
        case ExpressionType::UnaryOperation: delete (UnaryOperation*)expression; return;
        case ExpressionType::BinaryOperation: delete (BinaryOperation*)expression; return;
        case ExpressionType::None: default: return;
	}
}

Expression* Expression::Null() noexcept { return nullptr; }