#pragma once

#include <string>

#include <Syntax/Tokens/TokenType.h>
#include <Syntax/Tokens/Keyword.h>
#include <Syntax/Expressions/Operations/Operator.h>
#include <Syntax/Expressions/Assignment/AssignmentOperator.h>

namespace Yac::Syntax {

		unsigned int GetOperatorPrecedence(Operator op);
		Operator ToUnaryOperator(TokenType type);
		Operator ToBinaryOperator(TokenType type);
		AssignmentOperator ToAssignmentOperator(TokenType type);
		Keyword ToKeyword(const std::string& text);

}