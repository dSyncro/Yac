#pragma once

#include "Operator.h"

#include <yac/Syntax/Tokens/Token.h>
#include <yac/Syntax/Expressions/Expression.h>

namespace Yac {
	namespace Syntax {

		struct UnaryOperation : Expression {

		public:

			UnaryOperation(Operator operation, Expression* operand);
			~UnaryOperation();

			inline Operator operation() const noexcept { return _operation; }
			inline Expression* operand() const noexcept { return _operand; }

		private:

			Operator _operation;
			Expression* _operand;
		};

	}
}