#include "UnaryOperatorOverload.h"

using namespace Yac::DataTypes;
using namespace Yac::Syntax;

UnaryOperatorOverload::UnaryOperatorOverload(Operator operation, TypeSymbol operandType, TypeSymbol returnType)
	: Operation(operation), OperandType(operandType), ReturnType(returnType)
{
}