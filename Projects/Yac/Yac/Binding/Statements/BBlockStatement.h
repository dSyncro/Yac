#pragma once

#include <vector>

#include <Yac/Binding/Statements/BStatement.h>
#include <Yac/Binding/Scopes/BlockScope.h>

namespace Yac {

	struct BBlockStatement final : BStatement {

		BBlockStatement(const std::vector<BStatement*>& boundStatements, BlockScope* scope) 
			: BStatement(StatementType::Block, scope), statements(boundStatements) {}

		std::vector<BStatement*> statements;

	};

}