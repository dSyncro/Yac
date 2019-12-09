#pragma once

#include <string>
#include <vector>

#include <yac/Syntax/Tokens/Token.h>

namespace Yac {
	namespace Syntax {

		class Lexer
		{
		public:

			Lexer(std::string source);
			//~Lexer();

			Token Lex();

		private:

			void ReadWhitespace();
			void ReadWord();
			void ReadNumber(TokenType startingType = TokenType::Int);
			void ReadBinaryNumber();
			void ReadHexNumber();

			inline char Current() const noexcept { return Peek(0); }
			inline char Next() const noexcept { return Peek(1); }

			char Peek(unsigned int offset) const noexcept;

			TokenType _type = TokenType::None;
			unsigned int _position = 0, _start = 0;

			std::string _source, _text;
		};

	}
}
