#pragma once

#include <vector>

#include "Statement.h"

namespace Yac {
	namespace Syntax {

		struct BlockStatement : Statement {

		public:

			BlockStatement(const std::vector<Statement*>& statements) : Statement(StatementType::Block), _statements(statements) {}

			inline const std::vector<Statement*>& statements() const { return _statements; }

		private:

			std::vector<Statement*> _statements;
		};

	}
}