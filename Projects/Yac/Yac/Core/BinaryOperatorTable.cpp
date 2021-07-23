#include "BinaryOperatorTable.h"

using namespace Yac;

DeclarationResult BinaryOperatorTable::declare(const BBinaryOperator& op)
{
	if (exists(op.getSignature()))
		return DeclarationResult::AlreadyDeclared;

	bool result = _operators.emplace(op.getSignature(), &op.getReturnType()).second;
	return result ? DeclarationResult::Success : DeclarationResult::Failure;
}

bool BinaryOperatorTable::exists(const BBinarySignature& signature) const
{
	auto it = _operators.find(signature);
	return it != _operators.end();
}

const TypeSymbol& BinaryOperatorTable::getReturnType(const BBinarySignature& signature) const
{
	auto it = _operators.find(signature);

	if (it != _operators.end())
		return *it->second;

	return TypeSymbol::getInvalidTypeSymbol();
}