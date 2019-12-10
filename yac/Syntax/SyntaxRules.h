#pragma once

#include <string>

#include <yac/Syntax/Tokens/TokenType.h>
#include <yac/Syntax/Tokens/Keyword.h>
#include <yac/Syntax/Expressions/Operations/Operator.h>

namespace Yac {
	namespace Syntax {

		Operator ToUnaryOperator(TokenType type);
		Operator ToBinaryOperator(TokenType type);
		Keyword ToKeyword(std::string text);
		std::string ToString(TokenType type);

	}
}