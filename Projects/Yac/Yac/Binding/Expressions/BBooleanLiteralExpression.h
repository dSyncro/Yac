#pragma once

#include "BExpression.h"

#include <Yac/Core/Namespace.h>

namespace Yac {

	struct BBooleanLiteralExpression final : BExpression
	{
		BBooleanLiteralExpression(bool val = false)
			: BExpression(ExpressionType::BooleanLiteral, Namespace::getGlobalTypeTable().get("bool")), value(val) {}

		bool value;
	};

}