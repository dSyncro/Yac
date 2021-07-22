#pragma once

#include "BExpression.h"

#include <Yac/Binding/Scopes/Scope.h>
#include <Yac/Syntax/Expressions/StringLiteralExpression.h>

namespace Yac {

	struct BStringLiteralExpression final : BExpression {

	public:

		BStringLiteralExpression(const std::string& val, Scope* scope)
			: BExpression(ExpressionType::StringLiteral, scope->findTypeByName("string")),
			text(val) { }

		std::string text;
	};
}