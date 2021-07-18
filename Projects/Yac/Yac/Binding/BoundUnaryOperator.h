#pragma once

#include <Yac/Core/Types/TypeSymbol.h>
#include <Yac/Syntax/Operator.h>

namespace Yac {

	struct BoundUnaryOperator {

		BoundUnaryOperator(Operator op, const TypeSymbol& operandType, const TypeSymbol& returnType)
			: _operandType(&operandType), _returnType(&returnType) { }

		const TypeSymbol& getOperandType() const noexcept { return *_operandType; }
		const TypeSymbol& getReturnType() const noexcept { return *_returnType; }

	private:

		const TypeSymbol* _operandType;
		const TypeSymbol* _returnType;

	};
}