#pragma once

#include <string>

#include <Yac/Core/Primitives.h>
#include <Yac/Syntax/Tokens/TokenType.h>

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

	// Private members
	namespace {

		const char* AssignmentOperatorString[] = {
			"Unknown",
			"Assign",
			"SelfAdd",
			"SelfSubtract",
			"SelfMultiply",
			"SelfDivide",
			"SelfModulo",
			"SelfOr",
			"SelfAnd",
			"SelfXor",
			"SelfLeftShift",
			"SelfRightShift",
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

	inline std::string toString(AssignmentOperator op)
	{
		return AssignmentOperatorString[static_cast<UIntT>(op)];
	}

	UIntT getOperatorPrecedence(Operator op);
	Operator toUnaryOperator(TokenType type);
	Operator toBinaryOperator(TokenType type);
	AssignmentOperator toAssignmentOperator(TokenType type);

}