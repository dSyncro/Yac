#pragma once

#include <string>

#include "Statement.h"

#include <yac/Syntax/Expressions/Expression.h>
#include <yac/Syntax/Tokens/Keyword.h>

namespace Yac {
	namespace Syntax {

		struct VariableDeclaration : Statement {

		public:

			VariableDeclaration(Keyword keyword, std::string name, Expression* initializer);
			~VariableDeclaration() { delete _init; }

			inline Keyword keyword() const noexcept { return _keyword; }
			inline std::string name() const noexcept { return _name; }
			inline const Expression* initializer() const noexcept { return _init; }

		private:

			Keyword _keyword;
			std::string _name;
			Expression* _init;

		};

	}
}