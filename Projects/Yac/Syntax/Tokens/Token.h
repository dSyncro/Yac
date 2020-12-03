#pragma once

#include <string>
#include <vector>

#include "TokenType.h"

#include <Core/Primitives.h>
#include <Text/TextSpan.h>

namespace Yac::Syntax {

	class Token final {

	public:

		Token();
		Token(TokenType type, Yac::Text::TextSpan span, const std::string& text, Yac::UInt line);

		TokenType getType() const noexcept { return _type; }
		Yac::Text::TextSpan getSpan() const noexcept { return _span; }
		const std::string& getText() const noexcept { return _text; }
		Yac::UInt getLine() const noexcept { return _line; }

	private:

		TokenType _type;
		Yac::Text::TextSpan _span;
		std::string _text;

		Yac::UInt _line;

	};

	using TokenList = std::vector<Token>;
}

