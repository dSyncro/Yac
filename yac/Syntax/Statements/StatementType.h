#pragma once

namespace Yac {
	namespace Syntax {
		
		enum class StatementType {
			None,
			Block,
			VariableDeclaration,
			If,
			For,
			While,
			Expression
		};

	}
}