#pragma once

#include <Yac/Runtime/Stack.h>

namespace Yac::Runtime {

	VariableData convertByteToBool(Stack& stack, const void* value);
	VariableData convertByteToChar(Stack& stack, const void* value);
	VariableData convertByteToFloat(Stack& stack, const void* value);
	VariableData convertByteToDouble(Stack& stack, const void* value);
	VariableData convertByteToShort(Stack& stack, const void* value);
	VariableData convertByteToUShort(Stack& stack, const void* value);
	VariableData convertByteToInt(Stack& stack, const void* value);
	VariableData convertByteToUInt(Stack& stack, const void* value);
	VariableData convertByteToLong(Stack& stack, const void* value);
	VariableData convertByteToULong(Stack& stack, const void* value);

}