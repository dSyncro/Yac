#pragma once

#include "BExpression.h"
#include <Yac/Syntax/Operator.h>

namespace Yac {

	struct BUnaryExpression final : BExpression {

		BUnaryExpression(Operator op, BExpression* operand)
			: BExpression(ExpressionType::UnaryOperation, TypeSymbol::getInvalidTypeSymbol()),
			operandExpression(operand)
		{
			// TODO
		}

		BExpression* operandExpression;

	};
}