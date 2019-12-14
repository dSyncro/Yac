#pragma once

#include <vector>

#include "Statement.h"

namespace Yac {
	namespace Syntax {

		struct BlockStatement : Statement {

		public:

			BlockStatement(std::vector<Statement*> statements) : _statements(statements) {}

			const std::vector<Statement*>& statements() const { return _statements; }

		private:

			std::vector<Statement*> _statements;
		};

	}
}