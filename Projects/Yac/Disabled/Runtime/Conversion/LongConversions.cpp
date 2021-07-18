#include "LongConversions.h"

using namespace Yac;
using namespace Yac::Core;
using namespace Yac::Runtime;

VariableData Runtime::convertLongToBool(Stack& stack, const void* value)
{
	LongT actualValue = *reinterpret_cast<const LongT*>(value);
	bool converted = actualValue != 0 ? true : false;
	return stack.pushValue(TypeSymbol::getLongTypeSymbol(), &converted);
}

VariableData Runtime::convertLongToFloat(Stack& stack, const void* value)
{
	LongT actualValue = *reinterpret_cast<const LongT*>(value);
	float converted = static_cast<float>(actualValue);
	return stack.pushValue(TypeSymbol::getFloatTypeSymbol(), &converted);
}

VariableData Runtime::convertLongToDouble(Stack& stack, const void* value)
{
	LongT actualValue = *reinterpret_cast<const LongT*>(value);
	double converted = static_cast<double>(actualValue);
	return stack.pushValue(TypeSymbol::getDoubleTypeSymbol(), &converted);
}

VariableData Runtime::convertLongToShort(Stack& stack, const void* value)
{
	LongT actualValue = *reinterpret_cast<const LongT*>(value);
	ShortT converted = static_cast<ShortT>(actualValue);
	return stack.pushValue(TypeSymbol::getShortTypeSymbol(), &converted);
}

VariableData Runtime::convertLongToUShort(Stack& stack, const void* value)
{
	LongT actualValue = *reinterpret_cast<const LongT*>(value);
	UShortT converted = static_cast<UShortT>(actualValue);
	return stack.pushValue(TypeSymbol::getUShortTypeSymbol(), &converted);
}

VariableData Runtime::convertLongToInt(Stack& stack, const void* value)
{
	LongT actualValue = *reinterpret_cast<const LongT*>(value);
	IntT converted = static_cast<IntT>(actualValue);
	return stack.pushValue(TypeSymbol::getIntTypeSymbol(), &converted);
}

VariableData Runtime::convertLongToUInt(Stack& stack, const void* value)
{
	LongT actualValue = *reinterpret_cast<const LongT*>(value);
	UIntT converted = static_cast<UIntT>(actualValue);
	return stack.pushValue(TypeSymbol::getUIntTypeSymbol(), &converted);
}

VariableData Runtime::convertLongToULong(Stack& stack, const void* value)
{
	LongT actualValue = *reinterpret_cast<const LongT*>(value);
	ULongT converted = static_cast<ULongT>(actualValue);
	return stack.pushValue(TypeSymbol::getULongTypeSymbol(), &converted);
}
