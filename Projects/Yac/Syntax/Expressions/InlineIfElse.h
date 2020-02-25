#pragma once

#include "Expression.h"

namespace Yac::Syntax {

	struct InlineIfElse final : Expression {

	public:

		InlineIfElse(Expression* condition, Expression* trueExpression, Expression* falseExpression)
			: Expression(ExpressionType::InlineIfElse), _condition(condition), _trueExpression(trueExpression), _falseExpression(falseExpression)
		{
		}

		~InlineIfElse()
		{
			delete _condition;
			delete _trueExpression;
			delete _falseExpression;
		}

		inline const Expression* condition() const noexcept { return _condition; }
		inline const Expression* True() const noexcept { return _trueExpression; }
		inline const Expression* False() const noexcept { return _falseExpression; }

	private:

		Expression* _condition;
		Expression* _trueExpression;
		Expression* _falseExpression;
	};

}