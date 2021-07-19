#pragma once

#include "BExpression.h"

namespace Yac {

	struct BParenthesesExpression final : BExpression {

		BParenthesesExpression(BExpression* parenthesesExpr) 
			: BExpression(ExpressionType::Parentheses, parenthesesExpr->getType()), expression(parenthesesExpr) { }

		BExpression* expression;

	};

}