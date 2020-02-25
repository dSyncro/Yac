#pragma once

#include "Statement.h"

#include <Syntax/Expressions/Expression.h>

namespace Yac::Syntax {

	struct ExpressionStatement final : Statement {

	public:

		ExpressionStatement(Expression* expression);
		~ExpressionStatement() { delete _expr; }

		inline const Expression* expression() const noexcept { return _expr; }

	private:

		Expression* _expr;
	};
}