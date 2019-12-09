#pragma once

namespace Yac {
	namespace Syntax {

		enum class Operator {
			// Helper
			Unknown = 0,
			// Binary
			Addition = 1,
			Subtraction = 1,
			Multiplication = 2,
			Division = 2,
			// Unary
			Identity,
			Negation,
		};

	}
}