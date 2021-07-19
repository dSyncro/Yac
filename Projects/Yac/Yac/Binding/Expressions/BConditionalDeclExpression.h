#pragma once

#include <Yac/Binding/Expressions/BExpression.h>

namespace Yac {

	struct BConditionalDeclExpression final : BExpression
	{
		BConditionalDeclExpression(const std::string& identifier, BExpression* initializer)
			: BExpression(ExpressionType::ConditionalDeclaration, initializer->getType()), name(identifier) { }

		std::string name;
	};

}