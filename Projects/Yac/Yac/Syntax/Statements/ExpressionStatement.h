#pragma once

#include "Statement.h"

#include <Yac/Syntax/Expressions/Expression.h>

namespace Yac::Syntax {

	struct ExpressionStatement final : Statement {

	public:

		ExpressionStatement(Expression* expression);
		~ExpressionStatement() { delete _expr; }

		const Expression* getExpression() const noexcept { return _expr; }

	private:

		Expression* _expr;
	};
}