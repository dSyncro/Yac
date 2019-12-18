#include "SyntaxRules.h"

using namespace Yac::Syntax;

Operator Yac::Syntax::ToUnaryOperator(TokenType type)
{
	switch (type)
	{
		case TokenType::PlusSymbol: return Operator::Identity;
		case TokenType::MinusSymbol: return Operator::Negation;
		case TokenType::ExclamationMark: return Operator::LogicalNot;
		case TokenType::TildeSymbol: return Operator::OneComplementary;
		default: return Operator::Unknown;
	}
}

Operator Yac::Syntax::ToBinaryOperator(TokenType type)
{
	switch (type)
	{
        case TokenType::Comma: return Operator::Comma;
        case TokenType::DoublePipeSymbol: return Operator::LogicalOr;
        case TokenType::DoubleAndSymbol: return Operator::LogicalAnd;
        case TokenType::PipeSymbol: return Operator::BitwiseOr;
        case TokenType::CircumflexSymbol: return Operator::Xor;
        case TokenType::AndSymbol: return Operator::BitwiseAnd;
        case TokenType::DoubleEqualSymbol: return Operator::EqualTo;
        case TokenType::NotEqualSymbol: return Operator::NotEqualTo;
        case TokenType::LessSymbol: return Operator::LessThan;
        case TokenType::LessEqualSymbol: return Operator::LessEqualThan;
        case TokenType::GreaterSymbol: return Operator::GreaterThan;
        case TokenType::GreaterEqualSymbol: return Operator::GreaterEqualThan;
        case TokenType::ShiftLeftSymbol: return Operator::LeftShift;
        case TokenType::ShiftRightSymbol: return Operator::RightShift;
		case TokenType::PlusSymbol: return Operator::Addition;
		case TokenType::MinusSymbol: return Operator::Subtraction;
		case TokenType::StarSymbol: return Operator::Multiplication;
		case TokenType::SlashSymbol: return Operator::Division;
		default: return Operator::Unknown;
	}
}

Keyword Yac::Syntax::ToKeyword(std::string text)
{
    if (text == "true") return Keyword::True;
    else if (text == "false") return Keyword::False;
    else if (text == "let") return Keyword::Let;
    else if (text == "if") return Keyword::If;
    else if (text == "else") return Keyword::Else;
	else if (text == "for") return Keyword::For;
	else if (text == "while") return Keyword::While;
	else return Keyword::Unknown;
}

std::string Yac::Syntax::ToString(TokenType type)
{
	switch (type)
	{
        case TokenType::None: return "None";
        case TokenType::PlusSymbol: return "PlusSymbol";
        case TokenType::DoublePlusSymbol: return "DoublePlusSymbol";
        case TokenType::PlusEqualSymbol: return "PlusEqualSymbol";
        case TokenType::MinusSymbol: return "MinusSymbol";
        case TokenType::DoubleMinusSymbol: return "DoubleMinusSymbol";
        case TokenType::MinusEqualSymbol: return "MinusEqualSymbol";
        case TokenType::StarSymbol: return "StarSymbol";
        case TokenType::StarEqualSymbol: return "StarEqualSymbol";
        case TokenType::SlashSymbol: return "SlashSymbol";
        case TokenType::SlashEqualSymbol: return "SlashEqualSymbol";
        case TokenType::PercentSymbol: return "PercentSymbol";
        case TokenType::PercentEqualSymbol: return "PercentEqualSymbol";
        case TokenType::CircumflexSymbol: return "CircumflexSymbol";
        case TokenType::CircumflexEqualSymbol: return "CircumflexEqual";
        case TokenType::DotSymbol: return "DotSymbol";
        case TokenType::EqualSymbol: return "EqualSymbol";
        case TokenType::Semicolon: return "Semicolon";
        case TokenType::Int: return "Int";
        case TokenType::UInt: return "UInt";
        case TokenType::BinaryUInt: return "BinaryUInt";
        case TokenType::HexUInt: return "HexUInt";
        case TokenType::Float: return "Float";
        case TokenType::BinaryFloat: return "BinaryFloat";
        case TokenType::HexFloat: return "HexFloat";
        case TokenType::Double: return "Double";
        case TokenType::BinaryDouble: return "BinaryDouble";
        case TokenType::HexDouble: return "HexDouble";
        case TokenType::Word: return "Word";
        case TokenType::Identifier: return "Identifier";
        case TokenType::Keyword: return "Keyword";
        case TokenType::Whitespace: return "Whitespace";
        case TokenType::Newline: return "Newline";
        case TokenType::EndOfFile: return "EndOfFile";
        case TokenType::Unknown:
        default: return "Unknown";
	}
}