#pragma once

namespace Yac {
	namespace Syntax {

		enum class ExpressionType {
			None,
			IdentifierExpression,
			AssignmentExpression,
			ParenthesesExpression,
			NumericLiteral,
			BooleanLiteral,
			UnaryOperation,
			BinaryOperation,
			ConditionalDeclaration,
		};

	}
}