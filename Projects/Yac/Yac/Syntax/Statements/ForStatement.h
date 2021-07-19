#pragma once

#include "Statement.h"
#include <Yac/Syntax/Expressions/Expression.h>

namespace Yac {

	struct ForStatement final : Statement {

	public:

		ForStatement(Expression* assignment, Expression* condition, Expression* update, Statement* statement)
			: Statement(StatementType::For), _assignment(assignment), _condition(condition), _update(update), _statement(statement)
		{
		}

		~ForStatement()
		{
			delete _assignment;
			delete _condition;
			delete _update;
			delete _statement;
		}

		const Expression* getAssignment() const noexcept { return _assignment; }
		const Expression* getCondition() const noexcept { return _condition; }
		const Expression* getUpdate() const noexcept { return _update; }
		const Statement* getStatement() const noexcept { return _statement; }

	private:

		Expression* _assignment;
		Expression* _condition;
		Expression* _update;
		Statement* _statement;
	};
}