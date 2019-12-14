#pragma once

#include "Statement.h"
#include <yac/Syntax/Expressions/Expression.h>

namespace Yac {
	namespace Syntax {

		struct WhileStatement : Statement {

		public:

			WhileStatement(Expression* condition, Statement* body) : _condition(condition), _body(body) {}
			~WhileStatement() { Expression::Dispose(_condition); Statement::Dispose(_body); }

			inline const Expression* condition() const noexcept { return _condition; }
			inline const Statement* body() const noexcept { return _body; }

		private:

			Expression* _condition;
			Statement* _body;
		};

	}
}