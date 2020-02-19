#pragma once

namespace Yac::Syntax {
		
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