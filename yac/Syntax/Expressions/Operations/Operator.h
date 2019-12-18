#pragma once

namespace Yac {
	namespace Syntax {

		enum class Operator {
			// Helper
			Unknown = 0,

			// Binary
			Comma = 1,
			LogicalOr = 2,
			LogicalAnd = 3,
			BitwiseOr = 4,
			Xor = 5,
			BitwiseAnd = 6,
			EqualTo = 7,
			NotEqualTo = 7,
			LessThan = 8,
			LessEqualThan = 8,
			GreaterThan = 8,
			GreaterEqualThan = 8,
			LeftShift = 9,
			RightShift = 9,
			Addition = 10,
			Subtraction = 10,
			Multiplication = 11,
			Division = 11,
			Modulo = 11,

			// Unary
			Identity = 12,
			Negation = 12,
			PreIncrement = 12,
			PreDecrement = 12,
			LogicalNot = 12,
			OneComplementary = 12,
			PostIncrement = 13,
			PostDecrement = 13,
		};

	}
}