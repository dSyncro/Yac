#pragma once

#include <Yac/Syntax/Operator.h>
#include <Yac/Core/Types/TypeSymbol.h>

namespace Yac {

	struct BBinarySignature {

		BBinarySignature(const TypeSymbol& leftType, Operator op, const TypeSymbol& rightType)
			: _leftType(&leftType), _op(op), _rightType(&rightType) { }

		const Operator getOperator() const noexcept { return _op; }

		const TypeSymbol& getLeftType() const noexcept { return *_leftType; }
		const TypeSymbol& getRightType() const noexcept { return *_rightType; }

		bool operator ==(const BBinarySignature& other) const noexcept
		{
			return _leftType == other._leftType &&
				_op == other._op &&
				_rightType == other._rightType;
		}

	private:

		const TypeSymbol* _leftType;
		Operator _op;
		const TypeSymbol* _rightType;
	};

}

namespace std {

	template <>
	struct hash<Yac::BBinarySignature>
	{
		std::size_t operator()(const Yac::BBinarySignature& signature) const
		{
			static const int inverseGoldenRatio = 0x9e3779b9;

			std::size_t leftTypeHash = hash<std::string>()(signature.getLeftType().getName());
			std::size_t operatorHash = hash<std::size_t>()((std::size_t)signature.getOperator());
			std::size_t rightTypeHash = hash<std::string>()(signature.getRightType().getName());

			std::size_t finalHash = leftTypeHash ^ (operatorHash + inverseGoldenRatio + (leftTypeHash << 6) + (leftTypeHash >> 2));
			finalHash ^= rightTypeHash + inverseGoldenRatio + (finalHash << 6) + (finalHash >> 2);

			return finalHash;
		}
	};

}