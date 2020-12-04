#include "UnaryOperatorOverload.h"

using namespace Yac::DataTypes;
using namespace Yac::Syntax;

UnaryOperatorOverload::UnaryOperatorOverload(Operator operation, TypeSymbol operandType, TypeSymbol returnType)
	: operation(operation), operandType(operandType), returnType(returnType)
{
}