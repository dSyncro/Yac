#pragma once

#include <string>

#include "Expression.h"

namespace Yac {

	struct StringLiteralExpression final : Expression {

	public:

		StringLiteralExpression(const std::string& text)
			: Expression(ExpressionType::StringLiteral), _text(text) { }

		const std::string& getText() const noexcept { return _text; }

	private:

		std::string _text;
	};
}