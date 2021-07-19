#pragma once

#include <Yac/Binding/BBinaryOperator.h>

namespace Yac {

	class BinaryOperatorTable {

		void declare(const BBinaryOperator& op)
		{
			if (exists(op))
				return;

			_operators.push_back(op);
		}

		bool exists(const BBinaryOperator& op)
		{
			for (std::size_t i = 0; i < _operators.size(); i++)
			{
				if (BBinaryOperator::haveSameSignature(op, _operators[i]))
					return true;
			}

			return false;
		}

		const TypeSymbol& getReturnType(const TypeSymbol& leftType, Operator op, const TypeSymbol& rightType)
		{
			for (std::size_t i = 0; i < _operators.size(); i++)
			{
				BBinaryOperator current = _operators[i];
				if (current.getLeftType() == leftType && current.getOperator() == op && current.getRightType() == rightType)
					return current.getReturnType();
			}

			return TypeSymbol::getInvalidTypeSymbol();
		}

	private:

		std::vector<BBinaryOperator> _operators;
	};

}