#pragma once

#include "Statement.h"

#include <yac/Syntax/Expressions/Expression.h>

namespace Yac {
	namespace Syntax {

		struct ExpressionStatement : Statement {

		public:

			ExpressionStatement(Expression* expression);
			~ExpressionStatement();

			inline Expression* expression() const noexcept { return _expr; }

		private:

			Expression* _expr;
		};

	}
}