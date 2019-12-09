#pragma once

namespace Yac {
	namespace Syntax {

		enum class ExpressionType {
			None,
			IdentifierExpression,
			NumericLiteral,
			UnaryOperation,
			BinaryOperation,
		};

	}
}