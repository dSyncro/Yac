#include "BinaryOperatorOverload.h"

using namespace Yac::DataTypes;
using namespace Yac::Syntax;

BinaryOperatorOverload::BinaryOperatorOverload(Operator operation, TypeSymbol first, TypeSymbol second, TypeSymbol returnType)
	: Operation(operation), FirstOperandType(first), SecondOperandType(second), ReturnType(returnType) { }

bool Yac::DataTypes::operator ==(const BinaryOperatorOverload& a, const BinaryOperatorOverload& b)
{
	return &a == &b ||
		(a.Operation == b.Operation &&
			a.FirstOperandType == b.FirstOperandType &&
			a.SecondOperandType == b.SecondOperandType &&
			a.ReturnType == b.ReturnType);
}