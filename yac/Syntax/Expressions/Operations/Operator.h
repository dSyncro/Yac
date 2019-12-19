#pragma once

namespace Yac {
	namespace Syntax {

		enum class Operator {
			// Helper
			Unknown = 0,

			// Binary
			Comma = 0x1,
			LogicalOr = 0x2,
			LogicalAnd = 0x3,
			BitwiseOr = 0x4,
			Xor = 0x5,
			BitwiseAnd = 0x6,
			EqualTo = 0x7,
			NotEqualTo = 0x7,
			LessThan = 0x8,
			LessEqualThan = 0x8,
			GreaterThan = 0x8,
			GreaterEqualThan = 0x8,
			LeftShift = 0x9,
			RightShift = 0x9,
			Addition = 0xA,
			Subtraction = 0xA,
			Multiplication = 0xB,
			Division = 0xB,
			Modulo = 0xB,

			// Unary
			Identity = 0xC,
			Negation = 0xC,
			PreIncrement = 0xC,
			PreDecrement = 0xC,
			LogicalNot = 0xC,
			OneComplementary = 0xC,
			PostIncrement = 0xD,
			PostDecrement = 0xD,
		};
	}
}