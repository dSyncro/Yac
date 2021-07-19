#include "BBinaryOperator.h"

#include <Yac/Core/Namespace.h>

using namespace Yac;

std::vector<BBinaryOperator> BBinaryOperator::operators = {
	BBinaryOperator(Namespace::getGlobalTypeTable().get("bool"), Operator::BitwiseOr, Namespace::getGlobalTypeTable().get("bool"), Namespace::getGlobalTypeTable().get("bool")),
	BBinaryOperator(Namespace::getGlobalTypeTable().get("bool"), Operator::BitwiseAnd, Namespace::getGlobalTypeTable().get("bool"), Namespace::getGlobalTypeTable().get("bool")),
};

BBinaryOperator BBinaryOperator::bind(const TypeSymbol& leftType, Operator op, const TypeSymbol& rightType)
{
	for (const BBinaryOperator& bbop : operators)
	{
		if (leftType == bbop.getLeftType() && op == bbop.getOperator() && rightType == bbop.getRightType())
			return bbop;
	}

	const TypeSymbol& invalidType = TypeSymbol::getInvalidTypeSymbol();
	return BBinaryOperator(invalidType, Operator::Unknown, invalidType, invalidType);
}

bool BBinaryOperator::haveSameSignature(const BBinaryOperator& a, const BBinaryOperator& b)
{
	return
		a.getLeftType() == b.getLeftType() &&
		a.getOperator() == b.getOperator() &&
		a.getRightType() == b.getRightType();
}