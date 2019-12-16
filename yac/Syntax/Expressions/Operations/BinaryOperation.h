#pragma once

#include "Operator.h"

#include <yac/Syntax/Tokens/Token.h>
#include <yac/Syntax/Expressions/Expression.h>

namespace Yac {
	namespace Syntax {

		struct BinaryOperation : Expression {

		public:

			BinaryOperation(Expression* left, Operator operation, Expression* right);
			~BinaryOperation();

			inline const Expression* left() const noexcept { return _left; }
			inline Operator operation() const noexcept { return _operation; }
			inline const Expression* right() const noexcept { return _right; }

		private:

			Expression* _left;
			Operator _operation;
			Expression* _right;
		};

	}
}