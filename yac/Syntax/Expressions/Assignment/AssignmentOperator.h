#pragma once

namespace Yac {
	namespace Syntax {

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

		inline std::string ToString(AssignmentOperator op)
		{
			return AssignmentOperatorString[(unsigned int)op];
		}
	}
}