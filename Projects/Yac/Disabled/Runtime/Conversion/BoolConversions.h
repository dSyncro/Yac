#pragma once

#include <Yac/Runtime/Stack.h>

namespace Yac::Runtime {

	VariableData convertBoolToByte(Stack& stack, const void* value);
	VariableData convertBoolToChar(Stack& stack, const void* value);
	VariableData convertBoolToFloat(Stack& stack, const void* value);
	VariableData convertBoolToDouble(Stack& stack, const void* value);
	VariableData convertBoolToShort(Stack& stack, const void* value);
	VariableData convertBoolToUShort(Stack& stack, const void* value);
	VariableData convertBoolToInt(Stack& stack, const void* value);
	VariableData convertBoolToUInt(Stack& stack, const void* value);
	VariableData convertBoolToLong(Stack& stack, const void* value);
	VariableData convertBoolToULong(Stack& stack, const void* value);

}