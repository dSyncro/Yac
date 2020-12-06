#pragma once

#include <string>

#include "Statement.h"

#include <Yac/Syntax/Expressions/Expression.h>
#include <Yac/Syntax/Keyword.h>

namespace Yac::Syntax {

	struct VariableDeclarationStatement final : Statement {

	public:

		VariableDeclarationStatement(Keyword keyword, const std::string& name, Expression* initializer)
			:Statement(StatementType::VariableDeclaration), _keyword(keyword), _name(name), _init(initializer)
		{
		}

		~VariableDeclarationStatement() { delete _init; }

		Keyword getKeyword() const noexcept { return _keyword; }
		const std::string& getName() const noexcept { return _name; }
		const Expression* getInitializer() const noexcept { return _init; }

	private:

		Keyword _keyword;
		std::string _name;
		Expression* _init;

	};
}