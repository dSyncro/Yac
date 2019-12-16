#pragma once

namespace Yac {
	namespace Syntax {

		enum class TokenType {
			None,

			// Symbols
			PlusSymbol,             
			PlusEqualSymbol,
			MinusSymbol,
			MinusEqualSymbol,
			StarSymbol,
			StarEqualSymbol,
			SlashSymbol,
			SlashEqualSymbol,
			PercentSymbol,
			PercentEqual,
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

	}
}