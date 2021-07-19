#pragma once

namespace Yac {
		
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