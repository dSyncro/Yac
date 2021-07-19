#pragma once

#include <string>
#include <vector>

#include "Expression.h"

namespace Yac {

	struct FunctionCallExpression final : public Expression {

	public:

		FunctionCallExpression(const std::string& name, const std::vector<Expression*>& arguments)
			: Expression(ExpressionType::FunctionCall), _name(name), _arguments(arguments) { }

		const std::string& getName() const noexcept { return _name; }
		const std::vector<Expression*>& getArguments() const noexcept { return _arguments; }

	private:

		std::string _name;
		std::vector<Expression*> _arguments;

	};

}