#pragma once

#include "BExpression.h"

#include <Yac/Binding/Scopes/Scope.h>

namespace Yac {

	struct BIdentifierExpression final : BExpression {

		BIdentifierExpression(const std::string& idName, Scope* scope)
			: BExpression(ExpressionType::Identifier, scope->findTypeOfIdentifier(idName)), name(idName) { }

		std::string name;

	};

}