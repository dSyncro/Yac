#pragma once

#include <string>

#include "Expression.h"

namespace Yac {
	namespace Syntax {

		struct ConditionalDeclaration : Expression {

		public:

			ConditionalDeclaration(std::string name, Expression* initializer)
				: Expression(ExpressionType::ConditionalDeclaration), _name(name), _init(initializer) {}

			~ConditionalDeclaration() { delete _init; }

			inline std::string name() const noexcept { return _name; }
			inline const Expression* initializer() const noexcept { return _init; }

		private:

			std::string _name;
			Expression* _init;

		};

	}
}