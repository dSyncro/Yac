#pragma once

#include <vector>

#include "Statement.h"

namespace Yac {

	struct BlockStatement final : Statement {

	public:

		BlockStatement(const std::vector<Statement*>& statements) 
			: Statement(StatementType::Block), _statements(statements) {}

		const std::vector<Statement*>& getStatements() const { return _statements; }

	private:

		std::vector<Statement*> _statements;
	};

}