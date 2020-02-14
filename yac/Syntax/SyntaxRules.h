#pragma once

#include <string>

#include <yac/Syntax/Tokens/TokenType.h>
#include <yac/Syntax/Tokens/Keyword.h>
#include <yac/Syntax/Expressions/Operations/Operator.h>
#include <yac/Syntax/Expressions/Assignment/AssignmentOperator.h>

namespace Yac {
	namespace Syntax {

		unsigned int GetOperatorPrecedence(Operator op);
		Operator ToUnaryOperator(TokenType type);
		Operator ToBinaryOperator(TokenType type);
		AssignmentOperator ToAssignmentOperator(TokenType type);
		Keyword ToKeyword(const std::string& text);

	}
}