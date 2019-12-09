#pragma once

#include "Statement.h"

#include <yac/Syntax/Expressions/Expression.h>

namespace Yac {
	namespace Syntax {

		struct ExpressionStatement : Statement {

		public:

			ExpressionStatement(Expression* expression) :
				Statement(StatementType::Expression), _expr(expression) { }

			~ExpressionStatement() { Expression::Dispose(_expr); }

			inline Expression* expression() const noexcept { return _expr; }

		private:

			Expression* _expr;

		};

	}
}