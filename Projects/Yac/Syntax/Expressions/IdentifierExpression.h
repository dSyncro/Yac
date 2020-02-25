#pragma once

#include <string>

#include "Expression.h"

namespace Yac::Syntax {

	struct IdentifierExpression final : Expression {

	public:

		IdentifierExpression(std::string id)
			: Expression(ExpressionType::IdentifierExpression), _id(id)
		{
		}

		inline std::string identifier() const noexcept { return _id; }

	private:

		std::string _id;
	};
}