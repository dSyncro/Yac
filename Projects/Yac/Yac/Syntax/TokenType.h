#pragma once

#include <string>

namespace Yac::Syntax {

	enum class TokenType {
		None,

		// Symbols
		PlusSymbol,
		DoublePlusSymbol,
		PlusEqualSymbol,
		MinusSymbol,
		DoubleMinusSymbol,
		MinusEqualSymbol,
		StarSymbol,
		StarEqualSymbol,
		SlashSymbol,
		SlashEqualSymbol,
		PercentSymbol,
		PercentEqualSymbol,
		CircumflexSymbol,
		CircumflexEqualSymbol,
		DotSymbol,
		EqualSymbol,
		DoubleEqualSymbol,
		AndSymbol,
		AndEqualSymbol,
		DoubleAndSymbol,
		PipeSymbol,
		PipeEqualSymbol,
		DoublePipeSymbol,
		ExclamationMark,
		TildeSymbol,
		NotEqualSymbol,
		QuestionMarkSymbol,
		LessSymbol,
		LessEqualSymbol,
		ShiftLeftSymbol,
		SLEqualSymbol,
		GreaterSymbol,
		GreaterEqualSymbol,
		ShiftRightSymbol,
		SREqualSymbol,
		Colon,
		Semicolon,
		Comma,

		// Delimiters
		OpenParentheses,
		CloseParentheses,
		OpenSquared,
		CloseSquared,
		OpenBrackets,
		CloseBrackets,
		Quote,
		Apostrophe,

		// Numbers
		Int,
		UInt,
		BinaryUInt,
		HexUInt,
		Float,
		BinaryFloat,
		HexFloat,
		Double,
		BinaryDouble,
		HexDouble,

		// Strings
		Identifier,
		Keyword,
		StringLiteral,

		// Misc
		Whitespace,
		Newline,
		EndOfFile,
		Unknown
	};

	std::string toString(TokenType type);

	bool isNumeric(TokenType type);
	bool isWord(TokenType type);
}