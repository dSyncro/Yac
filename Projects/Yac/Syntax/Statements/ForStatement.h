#pragma once

#include "Statement.h"
#include <Syntax/Expressions/Expression.h>

namespace Yac::Syntax {

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

		inline const Expression* assignment() const noexcept { return _assignment; }
		inline const Expression* condition() const noexcept { return _condition; }
		inline const Expression* update() const noexcept { return _update; }
		inline const Statement* statement() const noexcept { return _statement; }

	private:

		Expression* _assignment;
		Expression* _condition;
		Expression* _update;
		Statement* _statement;
	};
}