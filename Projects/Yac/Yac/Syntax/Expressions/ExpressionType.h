#pragma once

namespace Yac::Syntax {

	enum class ExpressionType {
		None,
		Identifier,
		String,
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