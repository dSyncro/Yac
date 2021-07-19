#pragma once

#include <Yac/Binding/Expressions/BExpression.h>

namespace Yac {

	struct BInlineIfElse final : BExpression {

		BInlineIfElse(BExpression* condition, BExpression* ifTrue, BExpression* ifFalse) 
			: BExpression(ExpressionType::InlineIfElse, ifTrue->getType()),
			conditionExpression(condition), trueExpression(ifTrue), falseExpression(ifFalse) { }

		BExpression* conditionExpression;
		BExpression* trueExpression;
		BExpression* falseExpression;
	};

}