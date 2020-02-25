#pragma once

#include <string>

#include "Expression.h"

namespace Yac::Syntax {

	struct StringExpression final : Expression {

	public:

		StringExpression(std::string text)
			: Expression(ExpressionType::StringExpression), _text(text)
		{
		}

		inline std::string text() const noexcept { return _text; }

	private:

		std::string _text;
	};
}