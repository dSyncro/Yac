#pragma once

#include <string>

#include "Expression.h"

namespace Yac::Syntax {

	struct StringExpression final : Expression {

	public:

		StringExpression(const std::string& text)
			: Expression(ExpressionType::String), _text(text) { }

		const std::string& getText() const noexcept { return _text; }

	private:

		std::string _text;
	};
}