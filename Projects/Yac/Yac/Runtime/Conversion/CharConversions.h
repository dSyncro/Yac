#pragma once

#include <Yac/Runtime/Stack.h>

namespace Yac::Runtime {

	VariableData convertCharToByte(Stack& stack, const void* value);
	VariableData convertCharToBool(Stack& stack, const void* value);
	VariableData convertCharToFloat(Stack& stack, const void* value);
	VariableData convertCharToDouble(Stack& stack, const void* value);
	VariableData convertCharToShort(Stack& stack, const void* value);
	VariableData convertCharToUShort(Stack& stack, const void* value);
	VariableData convertCharToInt(Stack& stack, const void* value);
	VariableData convertCharToUInt(Stack& stack, const void* value);
	VariableData convertCharToLong(Stack& stack, const void* value);
	VariableData convertCharToULong(Stack& stack, const void* value);

}