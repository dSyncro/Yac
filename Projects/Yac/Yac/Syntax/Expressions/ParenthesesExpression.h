#pragma once

#include "Expression.h"

namespace Yac::Syntax {

	struct ParenthesesExpression final : Expression {

	public:

		ParenthesesExpression(Expression* expression)
			: Expression(ExpressionType::ParenthesesExpression), _expr(expression)
		{
		}

		~ParenthesesExpression() { delete _expr; }

		const Expression* getExpression() const noexcept { return _expr; }

	private:

		Expression* _expr;
	};
}