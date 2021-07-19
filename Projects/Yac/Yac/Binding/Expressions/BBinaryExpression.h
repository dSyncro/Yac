#pragma once

#include "BExpression.h"

#include <Yac/Syntax/Operator.h>
#include <Yac/Binding/BBinaryOperator.h>

namespace Yac {

	struct BBinaryExpression final : BExpression {

		BBinaryExpression(BExpression* left, Operator binaryOperator, BExpression* right)
			: BExpression(ExpressionType::BinaryOperation, TypeSymbol::getInvalidTypeSymbol()),
			leftExpression(left), op(binaryOperator), rightExpression(right)
		{
			BBinaryOperator boundOperator = BBinaryOperator::bind(left->getType(), binaryOperator, right->getType());

			// Actually assign return type
			_type = &boundOperator.getReturnType();
		}

		BExpression* leftExpression;
		Operator op;
		BExpression* rightExpression;

	};

}