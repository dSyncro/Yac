#pragma once

#include "Statement.h"
#include <Yac/Syntax/Expressions/Expression.h>

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

		const Expression* getCondition() const noexcept { return _condition; }
		const Statement* getStatement() const noexcept { return _statement; }
		const Statement* getElseStatement() const noexcept { return _else; }

		bool isElseStatementPresent() const { return _else != Statement::Null(); }

	private:

		Expression* _condition;
		Statement* _statement;
		Statement* _else;
	};

}