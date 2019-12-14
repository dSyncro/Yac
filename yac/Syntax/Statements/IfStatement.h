#pragma once

#include "Statement.h"
#include <yac/Syntax/Expressions/Expression.h>

namespace Yac {
	namespace Syntax {

		struct IfStatement : Statement {

		public:

			IfStatement(Expression* condition, Statement* statement, Statement* elseStatement) 
				: _condition(condition), _statement(statement), _else(elseStatement) {}

			~IfStatement() { Expression::Dispose(_condition); Statement::Dispose(_statement); Statement::Dispose(_else); }

			inline const Expression* condition() const noexcept { return _condition; }
			inline const Statement* statement() const noexcept { return _statement; }
			inline const Statement* elseStatement() const noexcept { return _else; }

		private:

			Expression* _condition;
			Statement* _statement;
			Statement* _else;
		};

	}
}