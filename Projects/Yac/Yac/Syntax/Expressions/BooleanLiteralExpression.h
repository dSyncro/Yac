#pragma once

#include "Expression.h"

namespace Yac {

	struct BooleanLiteralExpression final : Expression {

	public:

		BooleanLiteralExpression(bool value) 
			: Expression(ExpressionType::BooleanLiteral), _value(value) {}

		bool getValue() const noexcept { return _value; }

	private:

		bool _value;
	};
}