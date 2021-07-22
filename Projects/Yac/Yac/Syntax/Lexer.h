#pragma once

#include <string>

#include <Yac/Core/Primitives.h>
#include <Yac/Core/Errors/ErrorList.h>
#include <Yac/Core/Text/SourceText.h>
#include <Yac/Syntax/Token.h>

namespace Yac {

	class Lexer final
	{
	public:

		Lexer(const SourceText& source, Errors::ErrorList& errorList);

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

		const Line& getCurrentLine() const noexcept;

		TokenType _type = TokenType::None;
		UIntT _position = 0, _start = 0, _line = 0;

		std::string _text;
		SourceText _source;

		Errors::ErrorList& _errorList;
	};
}
