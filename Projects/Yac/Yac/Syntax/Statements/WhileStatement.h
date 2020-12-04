#pragma once

#include "Statement.h"
#include <Yac/Syntax/Expressions/Expression.h>

namespace Yac::Syntax {

	struct WhileStatement final : Statement {

	public:

		WhileStatement(Expression* condition, Statement* statement) : Statement(StatementType::While), _condition(condition), _statement(statement) {}
		~WhileStatement() { delete _condition; delete _statement; }

		const Expression* getCondition() const noexcept { return _condition; }
		const Statement* getStatement() const noexcept { return _statement; }

	private:

		Expression* _condition;
		Statement* _statement;
	};
}