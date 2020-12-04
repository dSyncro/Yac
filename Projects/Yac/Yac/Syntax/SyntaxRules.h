#pragma once

#include <string>

#include <Yac/Core/Primitives.h>
#include <Yac/Syntax/Tokens/TokenType.h>
#include <Yac/Syntax/Tokens/Keyword.h>
#include <Yac/Syntax/Expressions/Operations/Operator.h>
#include <Yac/Syntax/Expressions/Assignment/AssignmentOperator.h>

namespace Yac::Syntax {

		UIntT getOperatorPrecedence(Operator op);
		Operator toUnaryOperator(TokenType type);
		Operator toBinaryOperator(TokenType type);
		AssignmentOperator toAssignmentOperator(TokenType type);
		Keyword toKeyword(const std::string& text);

}