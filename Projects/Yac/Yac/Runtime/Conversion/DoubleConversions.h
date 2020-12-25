#pragma once

#include <Yac/Runtime/Stack.h>

namespace Yac::Runtime {

	VariableData convertDoubleToBool(Stack& stack, const void* value);
	VariableData convertDoubleToFloat(Stack& stack, const void* value);
	VariableData convertDoubleToShort(Stack& stack, const void* value);
	VariableData convertDoubleToUShort(Stack& stack, const void* value);
	VariableData convertDoubleToInt(Stack& stack, const void* value);
	VariableData convertDoubleToUInt(Stack& stack, const void* value);
	VariableData convertDoubleToLong(Stack& stack, const void* value);
	VariableData convertDoubleToULong(Stack& stack, const void* value);

}