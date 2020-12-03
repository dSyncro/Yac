#pragma once

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
		QuestionMark,
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

	namespace {

		const char* TokenTypeString[] = {
			"None",
			"PlusSymbol",
			"DoublePlusSymbol",
			"PlusEqualSymbol",
			"MinusSymbol",
			"DoubleMinusSymbol",
			"MinusEqualSymbol",
			"StarSymbol",
			"StarEqualSymbol",
			"SlashSymbol",
			"SlashEqualSymbol",
			"PercentSymbol",
			"PercentEqualSymbol",
			"CircumflexSymbol",
			"CircumflexEqualSymbol",
			"DotSymbol",
			"EqualSymbol",
			"DoubleEqualSymbol",
			"AndSymbol",
			"AndEqualSymbol",
			"DoubleAndSymbol",
			"PipeSymbol",
			"PipeEqualSymbol",
			"DoublePipeSymbol",
			"ExclamationMark",
			"TildeSymbol",
			"NotEqualSymbol",
			"QuestionMarkSymbol",
			"LessSymbol",
			"LessEqualSymbol",
			"ShiftLeftSymbol",
			"SLEqualSymbol",
			"GreaterSymbol",
			"GreaterEqualSymbol",
			"ShiftRightSymbol",
			"SREqualSymbol",
			"Colon",
			"Semicolon",
			"Comma",
			"OpenParentheses",
			"CloseParentheses",
			"OpenSquared",
			"CloseSquared",
			"OpenBrackets",
			"CloseBrackets",
			"Quote",
			"Apostrophe",
			"Int",
			"UInt",
			"BinaryUInt",
			"HexUInt",
			"Float",
			"BinaryFloat",
			"HexFloat",
			"Double",
			"BinaryDouble",
			"HexDouble",
			"Identifier",
			"Keyword",
			"StringLiteral",
			"Whitespace",
			"NewLine",
			"EndOfFile",
			"Unknown",
		};

	}

	inline std::string toString(TokenType type)
	{
		return TokenTypeString[(unsigned int)type];
	}

	inline bool isNumeric(TokenType type)
	{
		switch (type)
		{
			case TokenType::Int:
			case TokenType::UInt:
			case TokenType::BinaryUInt:
			case TokenType::HexUInt:
			case TokenType::Float:
			case TokenType::BinaryFloat:
			case TokenType::HexFloat:
			case TokenType::Double:
			case TokenType::BinaryDouble:
			case TokenType::HexDouble:
				return true;

			default: return false;
		}
	}

	inline bool isWord(TokenType type)
	{
		switch (type)
		{
			case TokenType::Identifier:
			case TokenType::Keyword:
			case TokenType::StringLiteral:
				return true;

			default: return false;
		}
	}
}