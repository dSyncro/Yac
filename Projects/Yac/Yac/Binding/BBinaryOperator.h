#pragma once

#include <vector>

#include <Yac/Syntax/Operator.h>
#include <Yac/Core/Types/TypeTable.h>

namespace Yac {

	struct NamespaceScope;

	struct BBinaryOperator {

		BBinaryOperator(const TypeSymbol& leftType, Operator op, const TypeSymbol& rightType, const TypeSymbol& returnType)
			: _leftType(&leftType), _op(op), _rightType(&rightType), _returnType(&returnType) {}

		const Operator getOperator() const noexcept { return _op; }

		const TypeSymbol& getLeftType() const noexcept { return *_leftType; }
		const TypeSymbol& getRightType() const noexcept { return *_rightType; }
		const TypeSymbol& getReturnType() const noexcept { return *_returnType; }

		static bool haveSameSignature(const BBinaryOperator& a, const BBinaryOperator& b);

	private:

		const TypeSymbol* _leftType;
		Operator _op;
		const TypeSymbol* _rightType;
		const TypeSymbol* _returnType;

	};
}