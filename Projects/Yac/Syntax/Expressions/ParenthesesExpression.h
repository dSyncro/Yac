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

		inline const Expression* expression() const noexcept { return _expr; }

	private:

		Expression* _expr;
	};
}