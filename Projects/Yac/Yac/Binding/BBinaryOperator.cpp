#include "BBinaryOperator.h"

#include <Yac/Binding/Scopes/NamespaceScope.h>

using namespace Yac;

bool BBinaryOperator::haveSameSignature(const BBinaryOperator& a, const BBinaryOperator& b)
{
	return
		a.getLeftType() == b.getLeftType() &&
		a.getOperator() == b.getOperator() &&
		a.getRightType() == b.getRightType();
}