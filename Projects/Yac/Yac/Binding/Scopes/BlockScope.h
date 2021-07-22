#pragma once

#include <Yac/Core/NameTable.h>
#include <Yac/Binding/Scopes/Scope.h>

namespace Yac {

	struct BlockScope : Scope {

		BlockScope(Scope* parent)
			: Scope(ScopeType::Block, parent) { }

	};
}