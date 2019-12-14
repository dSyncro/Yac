#pragma once

#include "Statement.h"
#include <yac/Syntax/Expressions/Expression.h>

namespace Yac {
	namespace Syntax {

		struct ForStatement : Statement {

		public:

			ForStatement(Expression* assignment, Expression* condition, Expression* update, Statement* statement)
				: _assignment(assignment), _condition(condition), _update(update), _statement(statement) {}

			~ForStatement() 
			{ 
				Expression::Dispose(_assignment);
				Expression::Dispose(_condition);
				Expression::Dispose(_update);
				Statement::Dispose(_statement); 
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
}