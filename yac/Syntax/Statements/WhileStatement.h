#pragma once

#include "Statement.h"
#include <yac/Syntax/Expressions/Expression.h>

namespace Yac::Syntax {

	struct WhileStatement final : Statement {

	public:

		WhileStatement(Expression* condition, Statement* statement) : Statement(StatementType::While), _condition(condition), _statement(statement) {}
		~WhileStatement() { delete _condition; delete _statement; }

		inline const Expression* condition() const noexcept { return _condition; }
		inline const Statement* statement() const noexcept { return _statement; }

	private:

		Expression* _condition;
		Statement* _statement;
	};
}