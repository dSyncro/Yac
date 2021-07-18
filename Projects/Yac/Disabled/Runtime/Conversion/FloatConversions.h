#pragma once

#include <Yac/Runtime/Stack.h>

namespace Yac::Runtime {

	VariableData convertFloatToBool(Stack& stack, const void* value);
	VariableData convertFloatToDouble(Stack& stack, const void* value);
	VariableData convertFloatToShort(Stack& stack, const void* value);
	VariableData convertFloatToUShort(Stack& stack, const void* value);
	VariableData convertFloatToInt(Stack& stack, const void* value);
	VariableData convertFloatToUInt(Stack& stack, const void* value);
	VariableData convertFloatToLong(Stack& stack, const void* value);
	VariableData convertFloatToULong(Stack& stack, const void* value);

}