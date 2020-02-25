#pragma once

#include "Statement.h"
#include <Syntax/Expressions/Expression.h>

namespace Yac::Syntax {

	struct IfStatement final : Statement {

	public:

		IfStatement(Expression* condition, Statement* statement, Statement* elseStatement)
			: Statement(StatementType::If), _condition(condition), _statement(statement), _else(elseStatement)
		{
		}

		~IfStatement()
		{
			delete _condition;
			delete _statement;
			delete _else;
		}

		inline const Expression* condition() const noexcept { return _condition; }
		inline const Statement* statement() const noexcept { return _statement; }
		inline const Statement* elseStatement() const noexcept { return _else; }

	private:

		Expression* _condition;
		Statement* _statement;
		Statement* _else;
	};

}