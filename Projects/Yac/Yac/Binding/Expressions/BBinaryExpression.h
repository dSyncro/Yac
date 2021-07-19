#pragma once

#include "BExpression.h"

#include <Yac/Syntax/Operator.h>
#include <Yac/Binding/BBinaryOperator.h>

namespace Yac {

	struct BBinaryExpression : BExpression {

		BBinaryExpression(BExpression* left, Operator op, BExpression* right)
			: BExpression(ExpressionType::BinaryOperation, TypeSymbol::getInvalidTypeSymbol()) 
		{
			BBinaryOperator boundOperator = BBinaryOperator::bind(left->getType(), op, right->getType());

			// Actually assign return type
			_type = &boundOperator.getReturnType();
		}

	};

}