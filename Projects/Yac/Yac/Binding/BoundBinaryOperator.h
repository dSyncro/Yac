#pragma once

#include <Yac/Core/Types/TypeSymbol.h>

namespace Yac {

	struct BoundBinaryOperator {

		BoundBinaryOperator(const TypeSymbol& leftType, const TypeSymbol& rightType, const TypeSymbol& returnType)
			: _leftType(&leftType), _rightType(&rightType), _returnType(&returnType) {}

		const TypeSymbol& getLeftType() const noexcept { return *_leftType; }
		const TypeSymbol& getRightType() const noexcept { return *_rightType; }
		const TypeSymbol& getReturnType() const noexcept { return *_returnType; }

	private:

		const TypeSymbol* _leftType;
		const TypeSymbol* _rightType;
		const TypeSymbol* _returnType;

	};
}