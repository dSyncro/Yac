#pragma once

#include "BExpression.h"

#include <Yac/Syntax/Operator.h>
#include <Yac/Binding/Scopes/NamespaceScope.h>

namespace Yac {

	struct BBinaryExpression final : BExpression {

		BBinaryExpression(BExpression* left, Operator binaryOperator, BExpression* right, Scope* scope)
			: BExpression(
				ExpressionType::BinaryOperation, 
				scope->findBinaryRetType(
					left->getType(), 
					binaryOperator,
					right->getType()
				)
			), leftExpression(left), op(binaryOperator), rightExpression(right) { }

		BExpression* leftExpression;
		Operator op;
		BExpression* rightExpression;

	};

}