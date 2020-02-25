#pragma once

#include <string>

#include "TokenType.h"

#include <Text/TextSpan.h>

namespace Yac::Syntax {

	class Token final {

	public:

		Token();
		Token(TokenType type, Yac::Text::TextSpan span, std::string text, unsigned int line);

		inline TokenType type() const noexcept { return _type; }
		inline Yac::Text::TextSpan span() const noexcept { return _span; }
		inline std::string text() const noexcept { return _text; }
		inline unsigned int line() const noexcept { return _line; }

	private:

		TokenType _type;
		Yac::Text::TextSpan _span;
		std::string _text;

		unsigned int _line;

	};
}

