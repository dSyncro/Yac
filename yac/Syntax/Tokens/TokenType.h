#pragma once

namespace Yac {
	namespace Syntax {

		enum class TokenType {
			None,

			// Symbols
			PlusSymbol,
			MinusSymbol,
			StarSymbol,
			SlashSymbol,
			CircumflexSymbol,
			DotSymbol,
			EqualSymbol,
			AndSymbol,
			PipeSymbol,
			ExclamationMark,
			QuestionMark,
			LessSymbol,
			GreaterSymbol,
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