#pragma once

#include "Expression.h"

namespace Yac {
	namespace Syntax {

		struct BooleanLiteral : Expression {

		public:

			BooleanLiteral(bool value) : Expression(ExpressionType::BooleanLiteral), _val(value) {}

			inline bool value() const noexcept { return _val; }

		private:

			bool _val;
		};

	}
}