#pragma once

#include <string>

#include "Expression.h"

namespace Yac {

	struct IdentifierExpression final : Expression {

	public:

		IdentifierExpression(const std::string& id)
			: Expression(ExpressionType::Identifier), _id(id) { }

		const std::string& getIdentifier() const noexcept { return _id; }

	private:

		std::string _id;
	};
}