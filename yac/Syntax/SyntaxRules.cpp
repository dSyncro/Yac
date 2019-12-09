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