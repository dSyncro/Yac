#pragma once

#include <Yac/Runtime/Stack.h>

namespace Yac::Runtime {

	VariableData convertUShortToBool(Stack& stack, const void* value);
	VariableData convertUShortToFloat(Stack& stack, const void* value);
	VariableData convertUShortToDouble(Stack& stack, const void* value);
	VariableData convertUShortToShort(Stack& stack, const void* value);
	VariableData convertUShortToInt(Stack& stack, const void* value);
	VariableData convertUShortToUInt(Stack& stack, const void* value);
	VariableData convertUShortToLong(Stack& stack, const void* value);
	VariableData convertUShortToULong(Stack& stack, const void* value);

}