#pragma once

#include "Statement.h"

#include <string>

#include <yac/Syntax/Lexer/Keyword.h>
#include <yac/Syntax/Expressions/Expression.h>

namespace Yac {
	namespace Syntax {

		struct VariableDeclaration : Statement {

		public:

			VariableDeclaration(Keyword keyword, std::string name, Expression* initializer) : 
				Statement(StatementType::VariableDeclaration), _keyword(keyword), _name(name), _init(initializer) { }

			~VariableDeclaration() { Expression::Dispose(_init); }

			inline Keyword keyword() const noexcept { return _keyword; }
			inline std::string name() const noexcept { return _name; }
			inline Expression* initializer() const noexcept { return _init; }

		private:

			Keyword _keyword;
			std::string _name;
			Expression* _init;

		};

	}
}