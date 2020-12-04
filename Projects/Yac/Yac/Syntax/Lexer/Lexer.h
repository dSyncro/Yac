#pragma once

#include <string>

#include <Yac/Core/Primitives.h>
#include <Yac/Errors/ErrorList.h>
#include <Yac/Syntax/Tokens/Token.h>
#include <Yac/Text/SourceText.h>

namespace Yac::Syntax {

	class Lexer final
	{
	public:

		Lexer(const Yac::Text::SourceText& source, Yac::Errors::ErrorList& errorList);

		Token consumeNext() noexcept;

	private:

		void stepLine() noexcept;

		void readWhitespace() noexcept;
		void readStringLiteral() noexcept;
		void readNumber(TokenType startingType = TokenType::Int) noexcept;
		void readBinaryNumber() noexcept;
		void readHexNumber() noexcept;
		Token produceWord() noexcept; 
		Token produceSymbol(TokenType type, const char* text, UIntT length = 1) noexcept;

		char getCurrent() const noexcept { return peek(0); }
		char getNext() const noexcept { return peek(1); }

		char peek(UIntT offset) const noexcept;

		const Yac::Text::Line& getCurrentLine() const noexcept;

		TokenType _type = TokenType::None;
		UIntT _position = 0, _start = 0, _line = 0;

		std::string _text;
		Yac::Text::SourceText _source;

		Yac::Errors::ErrorList& _errorList;
	};
}
