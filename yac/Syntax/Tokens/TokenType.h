#pragma once

namespace Yac {
	namespace Syntax {

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
			Word,
			Identifier,
			Keyword,

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
				"Word",
				"Identifier",
				"Keyword",
				"Whitespace",
				"NewLine",
				"EndOfFile",
				"Unknown",
			};

		}

		inline std::string ToString(TokenType type)
		{
			return TokenTypeString[(unsigned int)type];
		}
	}
}