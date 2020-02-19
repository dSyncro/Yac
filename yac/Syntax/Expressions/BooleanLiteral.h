#pragma once

#include "Expression.h"

namespace Yac::Syntax {

	struct BooleanLiteral final : Expression {

	public:

		BooleanLiteral(bool value) : Expression(ExpressionType::BooleanLiteral), _val(value) {}

		inline bool value() const noexcept { return _val; }

	private:

		bool _val;
	};
}