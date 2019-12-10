#include "SyntaxRules.h"

using namespace Yac::Syntax;

Operator Yac::Syntax::ToUnaryOperator(TokenType type)
{
	switch (type)
	{
		case TokenType::PlusSymbol: return Operator::Identity;
		case TokenType::MinusSymbol: return Operator::Negation;
		default: return Operator::Unknown;
	}
}

Operator Yac::Syntax::ToBinaryOperator(TokenType type)
{
	switch (type)
	{
		case TokenType::PlusSymbol: return Operator::Addition;
		case TokenType::MinusSymbol: return Operator::Subtraction;
		case TokenType::StarSymbol: return Operator::Multiplication;
		case TokenType::SlashSymbol: return Operator::Division;
		default: return Operator::Unknown;
	}
}

Keyword Yac::Syntax::ToKeyword(std::string text)
{
	if (text == "let") return Keyword::Let;
	if (text == "if") return Keyword::If;
	if (text == "for") return Keyword::For;
	if (text == "while") return Keyword::While;
	return Keyword::Unknown;
}

std::string Yac::Syntax::ToString(TokenType type)
{
	switch (type)
	{
        case Yac::Syntax::TokenType::None: return "None";
        case Yac::Syntax::TokenType::PlusSymbol: return "PlusSymbol";
        case Yac::Syntax::TokenType::MinusSymbol: return "MinusSymbol";
        case Yac::Syntax::TokenType::StarSymbol: return "StarSymbol";
        case Yac::Syntax::TokenType::SlashSymbol: return "SlashSymbol";
        case Yac::Syntax::TokenType::DotSymbol: return "DotSymbol";
        case Yac::Syntax::TokenType::EqualSymbol: return "EqualSymbol";
        case Yac::Syntax::TokenType::Int: return "Int";
        case Yac::Syntax::TokenType::UInt: return "UInt";
        case Yac::Syntax::TokenType::BinaryUInt: return "BinaryUInt";
        case Yac::Syntax::TokenType::HexUInt: return "HexUInt";
        case Yac::Syntax::TokenType::Float: return "Float";
        case Yac::Syntax::TokenType::BinaryFloat: return "BinaryFloat";
        case Yac::Syntax::TokenType::HexFloat: return "HexFloat";
        case Yac::Syntax::TokenType::Double: return "Double";
        case Yac::Syntax::TokenType::BinaryDouble: return "BinaryDouble";
        case Yac::Syntax::TokenType::HexDouble: return "HexDouble";
        case Yac::Syntax::TokenType::Word: return "Word";
        case Yac::Syntax::TokenType::Identifier: return "Identifier";
        case Yac::Syntax::TokenType::Keyword: return "Keyword";
        case Yac::Syntax::TokenType::Whitespace: return "Whitespace";
        case Yac::Syntax::TokenType::Newline: return "Newline";
        case Yac::Syntax::TokenType::EndOfFile: return "EndOfFile";
        case Yac::Syntax::TokenType::Unknown:
        default: return "Unknown";
	}
}