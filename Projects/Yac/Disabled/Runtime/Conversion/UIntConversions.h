#pragma once

#include <Yac/Runtime/Stack.h>

namespace Yac::Runtime {

	VariableData convertUIntToBool(Stack& stack, const void* value);
	VariableData convertUIntToFloat(Stack& stack, const void* value);
	VariableData convertUIntToDouble(Stack& stack, const void* value);
	VariableData convertUIntToShort(Stack& stack, const void* value);
	VariableData convertUIntToUShort(Stack& stack, const void* value);
	VariableData convertUIntToInt(Stack& stack, const void* value);
	VariableData convertUIntToLong(Stack& stack, const void* value);
	VariableData convertUIntToULong(Stack& stack, const void* value);

}