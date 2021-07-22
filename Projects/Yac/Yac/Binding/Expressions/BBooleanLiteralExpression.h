#pragma once

#include "BExpression.h"

#include <Yac/Binding/Scopes/Scope.h>

namespace Yac {

	struct BBooleanLiteralExpression final : BExpression
	{
		BBooleanLiteralExpression(bool val, Scope* scope)
			: BExpression(ExpressionType::BooleanLiteral, scope->findTypeByName("bool")), value(val) { }

		bool value;
	};

}