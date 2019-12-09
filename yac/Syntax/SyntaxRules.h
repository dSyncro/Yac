#pragma once

#include <string>

#include <yac/Syntax/Tokens/TokenType.h>
#include <yac/Syntax/Lexer/Keyword.h>
#include <yac/Syntax/Expressions/Expression.h>
#include <yac/Syntax/Expressions/Numeric/NumericLiteral.h>
#include <yac/Syntax/Expressions/Operations/Operator.h>
#include <yac/Syntax/Expressions/Operations/Operations.h>
#include <yac/Text/TextSpan.h>

namespace Yac {
	namespace Syntax {

		Operator ToUnaryOperator(TokenType type);
		Operator ToBinaryOperator(TokenType type);
		Keyword ToKeyword(std::string text);

	}
}