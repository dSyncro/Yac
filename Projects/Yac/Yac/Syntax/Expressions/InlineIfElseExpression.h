#pragma once

#include "Expression.h"

namespace Yac::Syntax {

	struct InlineIfElseExpression final : Expression {

	public:

		InlineIfElseExpression(Expression* condition, Expression* trueExpression, Expression* falseExpression)
			: Expression(ExpressionType::InlineIfElse), _condition(condition), _trueExpression(trueExpression), _falseExpression(falseExpression)
		{
		}

		~InlineIfElseExpression()
		{
			delete _condition;
			delete _trueExpression;
			delete _falseExpression;
		}

		const Expression* getCondition() const noexcept { return _condition; }
		const Expression* getTrueExpression() const noexcept { return _trueExpression; }
		const Expression* getFalseExpression() const noexcept { return _falseExpression; }

	private:

		Expression* _condition;
		Expression* _trueExpression;
		Expression* _falseExpression;
	};

}