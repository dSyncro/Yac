#pragma once

#include "ExpressionType.h"

namespace Yac {
	namespace Syntax {

		class Expression {

		public:

			inline ExpressionType type() const noexcept { return _type; }
			static Expression* Null() noexcept;

			static void Dispose(Expression* expression);

		protected:

			Expression(ExpressionType type) : _type(type) {}
			ExpressionType _type = ExpressionType::None;

		};

	}
}