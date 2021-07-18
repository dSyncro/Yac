#include "BoolConversions.h"

using namespace Yac;
using namespace Yac::Core;
using namespace Yac::Runtime;

VariableData Runtime::convertBoolToByte(Stack& stack, const void* value)
{
	bool actualValue = *reinterpret_cast<const bool*>(value);
	ByteT converted = actualValue ? 1 : 0;
	return stack.pushValue(TypeSymbol::getByteTypeSymbol(), &converted);
}

VariableData Runtime::convertBoolToChar(Stack& stack, const void* value)
{
	bool actualValue = *reinterpret_cast<const bool*>(value);
	char converted = actualValue ? 1 : 0;
	return stack.pushValue(TypeSymbol::getCharTypeSymbol(), &converted);
}

VariableData Runtime::convertBoolToFloat(Stack& stack, const void* value)
{
	bool actualValue = *reinterpret_cast<const bool*>(value);
	float converted = actualValue ? 1.0f : 0.0f;
	return stack.pushValue(TypeSymbol::getFloatTypeSymbol(), &converted);
}

VariableData Runtime::convertBoolToDouble(Stack& stack, const void* value)
{
	bool actualValue = *reinterpret_cast<const bool*>(value);
	double converted = actualValue ? 1.0 : 0.0;
	return stack.pushValue(TypeSymbol::getDoubleTypeSymbol(), &converted);
}

VariableData Runtime::convertBoolToShort(Stack& stack, const void* value)
{
	bool actualValue = *reinterpret_cast<const bool*>(value);
	ShortT converted = actualValue ? 1 : 0;
	return stack.pushValue(TypeSymbol::getShortTypeSymbol(), &converted);
}

VariableData Runtime::convertBoolToUShort(Stack& stack, const void* value)
{
	bool actualValue = *reinterpret_cast<const bool*>(value);
	UShortT converted = actualValue ? 1 : 0;
	return stack.pushValue(TypeSymbol::getUShortTypeSymbol(), &converted);
}

VariableData Runtime::convertBoolToInt(Stack& stack, const void* value)
{
	bool actualValue = *reinterpret_cast<const bool*>(value);
	IntT converted = actualValue ? 1 : 0;
	return stack.pushValue(TypeSymbol::getIntTypeSymbol(), &converted);
}

VariableData Runtime::convertBoolToUInt(Stack& stack, const void* value)
{
	bool actualValue = *reinterpret_cast<const bool*>(value);
	UIntT converted = actualValue ? 1 : 0;
	return stack.pushValue(TypeSymbol::getUIntTypeSymbol(), &converted);
}

VariableData Runtime::convertBoolToLong(Stack& stack, const void* value)
{
	bool actualValue = *reinterpret_cast<const bool*>(value);
	LongT converted = actualValue ? 1 : 0;
	return stack.pushValue(TypeSymbol::getLongTypeSymbol(), &converted);
}

VariableData Runtime::convertBoolToULong(Stack& stack, const void* value)
{
	bool actualValue = *reinterpret_cast<const bool*>(value);
	ULongT converted = actualValue ? 1 : 0;
	return stack.pushValue(TypeSymbol::getULongTypeSymbol(), &converted);
}