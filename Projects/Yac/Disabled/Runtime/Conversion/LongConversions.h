#pragma once

#include <Yac/Runtime/Stack.h>

namespace Yac::Runtime {

	VariableData convertLongToBool(Stack& stack, const void* value);
	VariableData convertLongToFloat(Stack& stack, const void* value);
	VariableData convertLongToDouble(Stack& stack, const void* value);
	VariableData convertLongToShort(Stack& stack, const void* value);
	VariableData convertLongToUShort(Stack& stack, const void* value);
	VariableData convertLongToInt(Stack& stack, const void* value);
	VariableData convertLongToUInt(Stack& stack, const void* value);
	VariableData convertLongToULong(Stack& stack, const void* value);

}