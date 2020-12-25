#pragma once

#include <Yac/Runtime/Stack.h>

namespace Yac::Runtime {

	VariableData convertULongToBool(Stack& stack, const void* value);
	VariableData convertULongToFloat(Stack& stack, const void* value);
	VariableData convertULongToDouble(Stack& stack, const void* value);
	VariableData convertULongToShort(Stack& stack, const void* value);
	VariableData convertULongToUShort(Stack& stack, const void* value);
	VariableData convertULongToInt(Stack& stack, const void* value);
	VariableData convertULongToUInt(Stack& stack, const void* value);
	VariableData convertULongToLong(Stack& stack, const void* value);

}