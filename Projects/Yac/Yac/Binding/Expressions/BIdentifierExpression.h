#pragma once

#include "BExpression.h"

#include <Yac/Core/Namespace.h>

namespace Yac {

	struct BIdentifierExpression final : BExpression {

		BIdentifierExpression(const std::string& idName, const Namespace& scope)
			: BExpression(ExpressionType::Identifier, scope.findTypeOfName(idName)), name(idName) { }

		std::string name;

	};

}