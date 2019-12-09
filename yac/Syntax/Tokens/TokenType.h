#pragma once

namespace Yac {
	namespace Syntax {

		enum class TokenType {
			None,
			PlusSymbol,
			MinusSymbol,
			StarSymbol,
			SlashSymbol,
			DotSymbol,
			EqualSymbol,
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
			Word,
			Identifier,
			Keyword,
			Whitespace,
			Newline,
			EndOfFile,
			Unknown
		};

	}
}