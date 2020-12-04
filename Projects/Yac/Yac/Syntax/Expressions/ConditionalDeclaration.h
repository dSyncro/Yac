#pragma once

#include <string>

#include "Expression.h"

namespace Yac::Syntax {

	struct ConditionalDeclaration final : Expression {

	public:

		ConditionalDeclaration(const std::string& name, Expression* initializer)
			: Expression(ExpressionType::ConditionalDeclaration), _name(name), _init(initializer)
		{ 
		}

		~ConditionalDeclaration() { delete _init; }

		const std::string& getName() const noexcept { return _name; }
		const Expression* getInitializer() const noexcept { return _init; }

	private:

		std::string _name;
		Expression* _init;

	};

}