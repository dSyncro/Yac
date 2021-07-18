#include "TokenType.h"

#include <string>

#include <Yac/Core/Base.h>

using namespace Yac;

std::string Yac::toString(TokenType type)
{
	switch (type)
	{
		ENUM_ELEMENT_TO_STRING(TokenType, None);
		ENUM_ELEMENT_TO_STRING(TokenType, PlusSymbol);
		ENUM_ELEMENT_TO_STRING(TokenType, DoublePlusSymbol);
		ENUM_ELEMENT_TO_STRING(TokenType, PlusEqualSymbol);
		ENUM_ELEMENT_TO_STRING(TokenType, MinusSymbol);
		ENUM_ELEMENT_TO_STRING(TokenType, DoubleMinusSymbol);
		ENUM_ELEMENT_TO_STRING(TokenType, MinusEqualSymbol);
		ENUM_ELEMENT_TO_STRING(TokenType, StarSymbol);
		ENUM_ELEMENT_TO_STRING(TokenType, StarEqualSymbol);
		ENUM_ELEMENT_TO_STRING(TokenType, SlashSymbol);
		ENUM_ELEMENT_TO_STRING(TokenType, SlashEqualSymbol);
		ENUM_ELEMENT_TO_STRING(TokenType, PercentEqualSymbol);
		ENUM_ELEMENT_TO_STRING(TokenType, CircumflexSymbol);
		ENUM_ELEMENT_TO_STRING(TokenType, CircumflexEqualSymbol);
		ENUM_ELEMENT_TO_STRING(TokenType, DotSymbol);
		ENUM_ELEMENT_TO_STRING(TokenType, EqualSymbol);
		ENUM_ELEMENT_TO_STRING(TokenType, DoubleEqualSymbol);
		ENUM_ELEMENT_TO_STRING(TokenType, AndSymbol);
		ENUM_ELEMENT_TO_STRING(TokenType, AndEqualSymbol);
		ENUM_ELEMENT_TO_STRING(TokenType, DoubleAndSymbol);
		ENUM_ELEMENT_TO_STRING(TokenType, PipeSymbol);
		ENUM_ELEMENT_TO_STRING(TokenType, PipeEqualSymbol);
		ENUM_ELEMENT_TO_STRING(TokenType, DoublePipeSymbol);
		ENUM_ELEMENT_TO_STRING(TokenType, ExclamationMark);
		ENUM_ELEMENT_TO_STRING(TokenType, TildeSymbol);
		ENUM_ELEMENT_TO_STRING(TokenType, NotEqualSymbol);
		ENUM_ELEMENT_TO_STRING(TokenType, QuestionMarkSymbol);
		ENUM_ELEMENT_TO_STRING(TokenType, LessSymbol);
		ENUM_ELEMENT_TO_STRING(TokenType, LessEqualSymbol);
		ENUM_ELEMENT_TO_STRING(TokenType, ShiftLeftSymbol);
		ENUM_ELEMENT_TO_STRING(TokenType, SLEqualSymbol);
		ENUM_ELEMENT_TO_STRING(TokenType, GreaterSymbol);
		ENUM_ELEMENT_TO_STRING(TokenType, GreaterEqualSymbol);
		ENUM_ELEMENT_TO_STRING(TokenType, ShiftRightSymbol);
		ENUM_ELEMENT_TO_STRING(TokenType, SREqualSymbol);
		ENUM_ELEMENT_TO_STRING(TokenType, Colon);
		ENUM_ELEMENT_TO_STRING(TokenType, Semicolon);
		ENUM_ELEMENT_TO_STRING(TokenType, Comma);
		ENUM_ELEMENT_TO_STRING(TokenType, OpenParentheses);
		ENUM_ELEMENT_TO_STRING(TokenType, CloseParentheses);
		ENUM_ELEMENT_TO_STRING(TokenType, OpenSquared);
		ENUM_ELEMENT_TO_STRING(TokenType, CloseSquared);
		ENUM_ELEMENT_TO_STRING(TokenType, OpenBrackets);
		ENUM_ELEMENT_TO_STRING(TokenType, CloseBrackets);
		ENUM_ELEMENT_TO_STRING(TokenType, Quote);
		ENUM_ELEMENT_TO_STRING(TokenType, Apostrophe);
		ENUM_ELEMENT_TO_STRING(TokenType, Int);
		ENUM_ELEMENT_TO_STRING(TokenType, UInt);
		ENUM_ELEMENT_TO_STRING(TokenType, BinaryUInt);
		ENUM_ELEMENT_TO_STRING(TokenType, HexUInt);
		ENUM_ELEMENT_TO_STRING(TokenType, Float);
		ENUM_ELEMENT_TO_STRING(TokenType, BinaryFloat);
		ENUM_ELEMENT_TO_STRING(TokenType, HexFloat);
		ENUM_ELEMENT_TO_STRING(TokenType, Double);
		ENUM_ELEMENT_TO_STRING(TokenType, BinaryDouble);
		ENUM_ELEMENT_TO_STRING(TokenType, HexDouble);
		ENUM_ELEMENT_TO_STRING(TokenType, Identifier);
		ENUM_ELEMENT_TO_STRING(TokenType, Keyword);
		ENUM_ELEMENT_TO_STRING(TokenType, StringLiteral);
		ENUM_ELEMENT_TO_STRING(TokenType, Whitespace);
		ENUM_ELEMENT_TO_STRING(TokenType, Newline);
		ENUM_ELEMENT_TO_STRING(TokenType, EndOfFile);
		default: return "Unknown";
	}
}

bool Yac::isNumeric(TokenType type)
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

bool Yac::isWord(TokenType type)
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