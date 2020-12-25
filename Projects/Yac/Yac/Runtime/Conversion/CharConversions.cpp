#include "CharConversions.h"

using namespace Yac;
using namespace Yac::Core;
using namespace Yac::Runtime;

VariableData Runtime::convertCharToByte(Stack& stack, const void* value)
{
	char actualValue = *reinterpret_cast<const char*>(value);
	ByteT converted = static_cast<ByteT>(actualValue);
	return stack.pushValue(TypeSymbol::getByteTypeSymbol(), &converted);
}

VariableData Runtime::convertCharToBool(Stack& stack, const void* value)
{
	char actualValue = *reinterpret_cast<const char*>(value);
	bool converted = actualValue != 0 ? true : false;
	return stack.pushValue(TypeSymbol::getBoolTypeSymbol(), &converted);
}

VariableData Runtime::convertCharToFloat(Stack& stack, const void* value)
{
	char actualValue = *reinterpret_cast<const char*>(value);
	float converted = static_cast<float>(actualValue);
	return stack.pushValue(TypeSymbol::getFloatTypeSymbol(), &converted);
}

VariableData Runtime::convertCharToDouble(Stack& stack, const void* value)
{
	char actualValue = *reinterpret_cast<const char*>(value);
	double converted = static_cast<double>(actualValue);
	return stack.pushValue(TypeSymbol::getDoubleTypeSymbol(), &converted);
}

VariableData Runtime::convertCharToShort(Stack& stack, const void* value)
{
	char actualValue = *reinterpret_cast<const char*>(value);
	ShortT converted = static_cast<ShortT>(actualValue);
	return stack.pushValue(TypeSymbol::getShortTypeSymbol(), &converted);
}

VariableData Runtime::convertCharToUShort(Stack& stack, const void* value)
{
	char actualValue = *reinterpret_cast<const char*>(value);
	UShortT converted = static_cast<UShortT>(actualValue);
	return stack.pushValue(TypeSymbol::getUShortTypeSymbol(), &converted);
}

VariableData Runtime::convertCharToInt(Stack& stack, const void* value)
{
	char actualValue = *reinterpret_cast<const char*>(value);
	IntT converted = static_cast<IntT>(actualValue);
	return stack.pushValue(TypeSymbol::getIntTypeSymbol(), &converted);
}

VariableData Runtime::convertCharToUInt(Stack& stack, const void* value)
{
	char actualValue = *reinterpret_cast<const char*>(value);
	UIntT converted = static_cast<UIntT>(actualValue);
	return stack.pushValue(TypeSymbol::getUIntTypeSymbol(), &converted);
}

VariableData Runtime::convertCharToLong(Stack& stack, const void* value)
{
	char actualValue = *reinterpret_cast<const char*>(value);
	LongT converted = static_cast<LongT>(actualValue);
	return stack.pushValue(TypeSymbol::getLongTypeSymbol(), &converted);
}

VariableData Runtime::convertCharToULong(Stack& stack, const void* value)
{
	char actualValue = *reinterpret_cast<const char*>(value);
	ULongT converted = static_cast<ULongT>(actualValue);
	return stack.pushValue(TypeSymbol::getULongTypeSymbol(), &converted);
}