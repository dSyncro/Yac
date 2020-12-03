#pragma once

#include <string>

#include <Syntax/Tokens/TokenType.h>
#include <Syntax/Tokens/Keyword.h>
#include <Syntax/Expressions/Operations/Operator.h>
#include <Syntax/Expressions/Assignment/AssignmentOperator.h>

namespace Yac::Syntax {

		unsigned int getOperatorPrecedence(Operator op);
		Operator toUnaryOperator(TokenType type);
		Operator toBinaryOperator(TokenType type);
		AssignmentOperator toAssignmentOperator(TokenType type);
		Keyword toKeyword(const std::string& text);

}