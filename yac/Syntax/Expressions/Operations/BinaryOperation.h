#pragma once

#include "Operator.h"

#include <yac/Syntax/Tokens/Token.h>
#include <yac/Syntax/Expressions/Expression.h>

namespace Yac {
	namespace Syntax {

		struct BinaryOperation : Expression {

		public:

			BinaryOperation(Expression* left, Operator operation, Expression* right)
				: Expression(ExpressionType::BinaryOperation), _left(left), _operation(operation), _right(right) { }

			~BinaryOperation() { Expression::Dispose(_left); Expression::Dispose(_right); }

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