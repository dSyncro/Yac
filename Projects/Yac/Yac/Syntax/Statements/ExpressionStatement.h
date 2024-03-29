#pragma once

#include "Statement.h"

#include <Yac/Syntax/Expressions/Expression.h>

namespace Yac {

	struct ExpressionStatement final : Statement {

	public:

		ExpressionStatement(Expression* expression):
			Statement(StatementType::Expression), _expr(expression) { }

		~ExpressionStatement() { delete _expr; }

		const Expression* getExpression() const noexcept { return _expr; }

	private:

		Expression* _expr;
	};
}