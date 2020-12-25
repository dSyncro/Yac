#pragma once

#include <Yac/Runtime/Stack.h>

namespace Yac::Runtime {

	VariableData convertIntToBool(Stack& stack, const void* value);
	VariableData convertIntToFloat(Stack& stack, const void* value);
	VariableData convertIntToDouble(Stack& stack, const void* value);
	VariableData convertIntToShort(Stack& stack, const void* value);
	VariableData convertIntToUShort(Stack& stack, const void* value);
	VariableData convertIntToUInt(Stack& stack, const void* value);
	VariableData convertIntToLong(Stack& stack, const void* value);
	VariableData convertIntToULong(Stack& stack, const void* value);

}