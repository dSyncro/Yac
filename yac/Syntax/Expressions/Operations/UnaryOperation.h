#pragma once

#include "Operator.h"

#include <yac/Syntax/Tokens/Token.h>
#include <yac/Syntax/Expressions/Expression.h>

namespace Yac {
	namespace Syntax {

		struct UnaryOperation : Expression {

		public:

			UnaryOperation(Operator operation, Expression* operand)
				: Expression(ExpressionType::UnaryOperation), _operation(operation), _operand(operand) {}

			~UnaryOperation() { Expression::Dispose(_operand); }

			inline Operator operation() const noexcept { return _operation; }
			inline Expression* operand() const noexcept { return _operand; }

		private:

			Operator _operation;
			Expression* _operand;
		};

	}
}