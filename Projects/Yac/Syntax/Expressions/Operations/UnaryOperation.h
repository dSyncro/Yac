#pragma once

#include "Operator.h"

#include <Syntax/Tokens/Token.h>
#include <Syntax/Expressions/Expression.h>

namespace Yac {
	namespace Syntax {

		struct UnaryOperation : Expression {

		public:

			UnaryOperation(Operator operation, Expression* operand);
			~UnaryOperation();

			inline Operator operation() const noexcept { return _operation; }
			inline const Expression* operand() const noexcept { return _operand; }

		private:

			Operator _operation;
			Expression* _operand;
		};

	}
}