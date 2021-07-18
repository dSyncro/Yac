#include "ByteConversions.h"

using namespace Yac;
using namespace Yac::Core;
using namespace Yac::Runtime;

VariableData Runtime::convertByteToBool(Stack& stack, const void* value)
{
	ByteT actualValue = *reinterpret_cast<const ByteT*>(value);
	bool converted = actualValue != 0 ? true : false;
	return stack.pushValue(TypeSymbol::getBoolTypeSymbol(), &converted);
}

VariableData Runtime::convertByteToChar(Stack& stack, const void* value)
{
	ByteT actualValue = *reinterpret_cast<const ByteT*>(value);
	char converted = static_cast<char>(actualValue);
	return stack.pushValue(TypeSymbol::getCharTypeSymbol(), &converted);
}

VariableData Runtime::convertByteToFloat(Stack& stack, const void* value)
{
	ByteT actualValue = *reinterpret_cast<const ByteT*>(value);
	float converted = static_cast<float>(actualValue);
	return stack.pushValue(TypeSymbol::getFloatTypeSymbol(), &converted);
}

VariableData Runtime::convertByteToDouble(Stack& stack, const void* value)
{
	ByteT actualValue = *reinterpret_cast<const ByteT*>(value);
	double converted = static_cast<double>(actualValue);
	return stack.pushValue(TypeSymbol::getDoubleTypeSymbol(), &converted);
}

VariableData Runtime::convertByteToShort(Stack& stack, const void* value)
{
	ByteT actualValue = *reinterpret_cast<const ByteT*>(value);
	ShortT converted = static_cast<ShortT>(actualValue);
	return stack.pushValue(TypeSymbol::getShortTypeSymbol(), &converted);
}

VariableData Runtime::convertByteToUShort(Stack& stack, const void* value)
{
	ByteT actualValue = *reinterpret_cast<const ByteT*>(value);
	UShortT converted = static_cast<UShortT>(actualValue);
	return stack.pushValue(TypeSymbol::getUShortTypeSymbol(), &converted);
}

VariableData Runtime::convertByteToInt(Stack& stack, const void* value)
{
	ByteT actualValue = *reinterpret_cast<const ByteT*>(value);
	IntT converted = static_cast<IntT>(actualValue);
	return stack.pushValue(TypeSymbol::getIntTypeSymbol(), &converted);
}

VariableData Runtime::convertByteToUInt(Stack& stack, const void* value)
{
	ByteT actualValue = *reinterpret_cast<const ByteT*>(value);
	UIntT converted = static_cast<UIntT>(actualValue);
	return stack.pushValue(TypeSymbol::getUIntTypeSymbol(), &converted);
}

VariableData Runtime::convertByteToLong(Stack& stack, const void* value)
{
	ByteT actualValue = *reinterpret_cast<const ByteT*>(value);
	LongT converted = static_cast<LongT>(actualValue);
	return stack.pushValue(TypeSymbol::getLongTypeSymbol(), &converted);
}

VariableData Runtime::convertByteToULong(Stack& stack, const void* value)
{
	ByteT actualValue = *reinterpret_cast<const ByteT*>(value);
	ULongT converted = static_cast<ULongT>(actualValue);
	return stack.pushValue(TypeSymbol::getULongTypeSymbol(), &converted);
}