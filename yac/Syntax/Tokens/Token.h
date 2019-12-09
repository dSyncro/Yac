#pragma once

#include <string>

#include "TokenType.h"

#include <yac/Text/TextSpan.h>

namespace Yac {
	namespace Syntax {

		class Token {

		public:

			Token() : _type(TokenType::None), _span({ 0, 0 }), _text("") {}
			Token(TokenType type, Yac::Text::TextSpan span, std::string text) : _type(type), _span(span), _text(text) {}
			~Token() {}

			inline TokenType type() const noexcept { return _type; }
			inline Yac::Text::TextSpan span() const noexcept { return _span; }
			inline std::string text() const noexcept { return _text; }

			inline static Token Empty() noexcept { return Token(TokenType::None, { 0, 0 }, ""); }

		private:

			TokenType _type;
			Yac::Text::TextSpan _span;

			std::string _text;

		};

	}
}

