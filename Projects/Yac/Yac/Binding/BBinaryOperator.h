#pragma once

#include <vector>

#include <Yac/Syntax/Operator.h>
#include <Yac/Core/Types/TypeTable.h>

namespace Yac {

	struct BBinaryOperator {

		BBinaryOperator(const TypeSymbol& leftType, Operator op, const TypeSymbol& rightType, const TypeSymbol& returnType)
			: _leftType(&leftType), _op(op), _rightType(&rightType), _returnType(&returnType) {}

		const Operator getOperator() const noexcept { return _op; }

		const TypeSymbol& getLeftType() const noexcept { return *_leftType; }
		const TypeSymbol& getRightType() const noexcept { return *_rightType; }
		const TypeSymbol& getReturnType() const noexcept { return *_returnType; }

		static bool haveSameSignature(const BBinaryOperator& a, const BBinaryOperator& b);

		static std::vector<BBinaryOperator> operators;
		static BBinaryOperator bind(const TypeSymbol& leftType, Operator op, const TypeSymbol& rightType);

	private:

		const TypeSymbol* _leftType;
		Operator _op;
		const TypeSymbol* _rightType;
		const TypeSymbol* _returnType;

	};
}