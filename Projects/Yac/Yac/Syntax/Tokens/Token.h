#pragma once

#include <string>
#include <vector>

#include "TokenType.h"

#include <Yac/Core/Primitives.h>
#include <Yac/Core/Text/TextSpan.h>

namespace Yac::Syntax {

	class Token final {

	public:

		Token() : Token(TokenType::None, { 0, 0 }, "", 0) {}
		Token(TokenType type, Text::TextSpan span, const std::string& text, UIntT line)
			: _type(type), _span(span), _text(text), _line(line) { }

		TokenType getType() const noexcept { return _type; }
		Text::TextSpan getSpan() const noexcept { return _span; }
		const std::string& getText() const noexcept { return _text; }
		UIntT getLine() const noexcept { return _line; }

	private:

		TokenType _type;
		Text::TextSpan _span;
		std::string _text;

		UIntT _line;

	};

	using TokenList = std::vector<Token>;
}

