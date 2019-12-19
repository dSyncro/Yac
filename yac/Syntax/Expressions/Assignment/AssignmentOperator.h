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

	}
}