#pragma once

#include "Expression.h"

namespace Yac {

	struct ParenthesesExpression final : Expression {

	public:

		ParenthesesExpression(Expression* expression)
			: Expression(ExpressionType::Parentheses), _expr(expression) { }

		~ParenthesesExpression() { delete _expr; }

		const Expression* getExpression() const noexcept { return _expr; }

	private:

		Expression* _expr;
	};
}