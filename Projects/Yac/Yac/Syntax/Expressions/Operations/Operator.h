#pragma once

#include <Yac/Core/Primitives.h>

#include <string>

namespace Yac::Syntax {

	enum class Operator {
		// Helper
		Unknown,

		// Binary
		Comma,
		LogicalOr,
		LogicalAnd,
		BitwiseOr,
		Xor,
		BitwiseAnd,
		EqualTo,
		NotEqualTo,
		LessThan,
		LessEqualThan,
		GreaterThan,
		GreaterEqualThan,
		LeftShift,
		RightShift,
		Addition,
		Subtraction,
		Multiplication,
		Division,
		Modulo,

		// Unary
		Identity,
		Negation,
		PreIncrement,
		PreDecrement,
		LogicalNot,
		OneComplementary,
		PostIncrement,
		PostDecrement,
	};

	// Private Members
	namespace {

		const char* OperatorString[] = {
			"Unknown",
			"Comma",
			"LogicalOr",
			"LogicalAnd",
			"BitwiseOr",
			"Xor",
			"BitwiseAnd",
			"EqualTo",
			"NotEqualTo",
			"LessThan",
			"LessEqualThan",
			"GreatherThan",
			"GreatherEqualThan",
			"LeftShift",
			"RightShift",
			"Addition",
			"Subtraction",
			"Multiplication",
			"Division",
			"Modulo",
			"Identity",
			"Negation",
			"PreIncrement",
			"PreDecrement",
			"LogicalNot",
			"OneComplementary",
			"PostIncrement",
			"PostDecrement",
		};

	}

	inline bool isBinary(Operator op)
	{
		return Operator::Comma <= op && op <= Operator::Modulo;
	}

	inline bool isUnary(Operator op)
	{
		return Operator::Identity <= op && op <= Operator::PostDecrement;
	}

	inline std::string toString(Operator op)
	{
		return OperatorString[static_cast<UIntT>(op)];
	}
}