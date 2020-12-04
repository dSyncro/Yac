#include "BinaryOperatorOverload.h"

using namespace Yac::DataTypes;
using namespace Yac::Syntax;

BinaryOperatorOverload::BinaryOperatorOverload(Operator operation, TypeSymbol first, TypeSymbol second, TypeSymbol returnType)
	: operation(operation), firstOperandType(first), secondOperandType(second), returnType(returnType) { }

bool Yac::DataTypes::operator ==(const BinaryOperatorOverload& a, const BinaryOperatorOverload& b)
{
	return &a == &b ||
		(a.operation == b.operation &&
			a.firstOperandType == b.firstOperandType &&
			a.secondOperandType == b.secondOperandType &&
			a.returnType == b.returnType);
}