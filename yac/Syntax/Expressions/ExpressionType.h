#pragma once

namespace Yac::Syntax {

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
		InlineIfElse,
	};
}