#pragma once

#include <string>

#include <yac/Syntax/Tokens/Token.h>
#include <yac/Errors/ErrorReporter.h>
#include <yac/Text/SourceText.h>

namespace Yac {
	namespace Syntax {

		class Lexer
		{
		public:

			Lexer(Yac::Text::SourceText text);

			Token Lex() noexcept;

		private:

			void StepLine() noexcept;

			void ReadWhitespace() noexcept;
			void ReadWord() noexcept;
			void ReadNumber(TokenType startingType = TokenType::Int) noexcept;
			void ReadBinaryNumber() noexcept;
			void ReadHexNumber() noexcept;
			Token ReadSymbol(TokenType type, const char* text, unsigned int length = 1) noexcept;

			inline char Current() const noexcept { return Peek(0); }
			inline char Next() const noexcept { return Peek(1); }

			char Peek(unsigned int offset) const noexcept;

			const Yac::Text::Line& CurrentLine() const noexcept;

			TokenType _type = TokenType::None;
			unsigned int _position = 0, _start = 0, _line = 0;

			std::string _text;
			Yac::Text::SourceText _source;

			Yac::Errors::ErrorReporter _reporter;
		};

	}
}
