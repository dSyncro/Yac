#pragma once

#include "BExpression.h"

#include <Yac/Core/Namespace.h>
#include <Yac/Syntax/Expressions/StringLiteralExpression.h>

namespace Yac {

	struct BStringLiteralExpression final : BExpression {

	public:

		BStringLiteralExpression(const std::string& val)
			: BExpression(ExpressionType::StringLiteral, Namespace::getGlobalTypeTable().get("string")),
			text(val) { }

		std::string text;
	};
}