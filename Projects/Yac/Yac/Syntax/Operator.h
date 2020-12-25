#pragma once

#include <string>

#include <Yac/Core/Primitives.h>
#include <Yac/Syntax/TokenType.h>

namespace Yac::Syntax {

	enum class Operator {

		// Unary
		Identity,
		Negation,
		PreIncrement,
		PreDecrement,
		LogicalNot,
		OneComplementary,
		PostIncrement,
		PostDecrement,

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

		// Helper
		Unknown,
	};

	enum class AssignmentOperator {
		Unknown,
		Assign,
		Add,
		Subtract,
		Multiply,
		Divide,
		Modulo,
		Or,
		And,
		Xor,
		LeftShift,
		RightShift,
	};

	inline bool isBinary(Operator op)
	{
		return Operator::Comma <= op && op <= Operator::Modulo;
	}

	inline bool isUnary(Operator op)
	{
		return Operator::Identity <= op && op <= Operator::PostDecrement;
	}

	std::string toString(Operator op);
	std::string toString(AssignmentOperator op);

	UIntT getOperatorPrecedence(Operator op);
	Operator toUnaryOperator(TokenType type);
	Operator toBinaryOperator(TokenType type);
	AssignmentOperator toAssignmentOperator(TokenType type);

	constexpr UIntT getUnaryOperatorCount() { return 8; }
	constexpr UIntT getBinaryOperatorCount() { return 19; }

}