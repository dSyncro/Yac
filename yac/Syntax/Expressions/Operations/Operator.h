#pragma once

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
	}
}