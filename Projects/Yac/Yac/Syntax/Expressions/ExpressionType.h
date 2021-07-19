#pragma once

namespace Yac {
	enum class ExpressionType {
		None,
		Identifier,
		StringLiteral,
		Assignment,
		Parentheses,
		NumericLiteral,
		BooleanLiteral,
		UnaryOperation,
		BinaryOperation,
		ConditionalDeclaration,
		InlineIfElse,
		FunctionCall,
	};
}