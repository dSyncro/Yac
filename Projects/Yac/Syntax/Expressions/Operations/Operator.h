#pragma once

#include <string>

namespace Yac {
	namespace Syntax {

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

		inline std::string toString(Operator op)
		{
			return OperatorString[(unsigned int)op];
		}

	}
}