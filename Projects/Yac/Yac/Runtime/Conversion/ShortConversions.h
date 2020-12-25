#pragma once

#include <Yac/Runtime/Stack.h>

namespace Yac::Runtime {

	VariableData convertShortToBool(Stack& stack, const void* value);
	VariableData convertShortToFloat(Stack& stack, const void* value);
	VariableData convertShortToDouble(Stack& stack, const void* value);
	VariableData convertShortToUShort(Stack& stack, const void* value);
	VariableData convertShortToInt(Stack& stack, const void* value);
	VariableData convertShortToUInt(Stack& stack, const void* value);
	VariableData convertShortToLong(Stack& stack, const void* value);
	VariableData convertShortToULong(Stack& stack, const void* value);

}