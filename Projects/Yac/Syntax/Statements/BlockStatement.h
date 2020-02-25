#pragma once

#include <vector>

#include "Statement.h"

namespace Yac::Syntax {

	struct BlockStatement final : Statement {

	public:

		BlockStatement(const std::vector<Statement*>& statements) : Statement(StatementType::Block), _statements(statements) {}

		inline const std::vector<Statement*>& statements() const { return _statements; }

	private:

		std::vector<Statement*> _statements;
	};

}