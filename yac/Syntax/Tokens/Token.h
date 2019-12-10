#pragma once

#include <string>

#include "TokenType.h"

#include <yac/Text/TextSpan.h>

namespace Yac {
	namespace Syntax {

		class Token {

		public:

			Token();
			Token(TokenType type, Yac::Text::TextSpan span, std::string text);

			inline TokenType type() const noexcept { return _type; }
			inline Yac::Text::TextSpan span() const noexcept { return _span; }
			inline std::string text() const noexcept { return _text; }

		private:

			TokenType _type;
			Yac::Text::TextSpan _span;

			std::string _text;

		};

	}
}

