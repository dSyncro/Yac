#pragma once

namespace Yac::Syntax {

	enum class ExpressionType {
		None,
		IdentifierExpression,
		StringExpression,
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