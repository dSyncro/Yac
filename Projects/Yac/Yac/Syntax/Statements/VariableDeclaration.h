#pragma once

#include <string>

#include "Statement.h"

#include <Yac/Syntax/Expressions/Expression.h>
#include <Yac/Syntax/Tokens/Keyword.h>

namespace Yac::Syntax {

	struct VariableDeclaration final : Statement {

	public:

		VariableDeclaration(Keyword keyword, const std::string& name, Expression* initializer);
		~VariableDeclaration() { delete _init; }

		Keyword getKeyword() const noexcept { return _keyword; }
		const std::string& getName() const noexcept { return _name; }
		const Expression* getInitializer() const noexcept { return _init; }

	private:

		Keyword _keyword;
		std::string _name;
		Expression* _init;

	};
}