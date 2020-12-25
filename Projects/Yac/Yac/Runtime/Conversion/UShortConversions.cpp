#include "UShortConversions.h"

using namespace Yac;
using namespace Yac::Core;
using namespace Yac::Runtime;

VariableData Runtime::convertUShortToBool(Stack& stack, const void* value)
{
	UShortT actualValue = *reinterpret_cast<const UShortT*>(value);
	bool converted = actualValue != 0 ? true : false;
	return stack.pushValue(TypeSymbol::getBoolTypeSymbol(), &converted);
}

VariableData Runtime::convertUShortToFloat(Stack& stack, const void* value)
{
	UShortT actualValue = *reinterpret_cast<const UShortT*>(value);
	float converted = static_cast<float>(actualValue);
	return stack.pushValue(TypeSymbol::getFloatTypeSymbol(), &converted);
}

VariableData Runtime::convertUShortToDouble(Stack& stack, const void* value)
{
	UShortT actualValue = *reinterpret_cast<const UShortT*>(value);
	double converted = static_cast<double>(actualValue);
	return stack.pushValue(TypeSymbol::getDoubleTypeSymbol(), &converted);
}

VariableData Runtime::convertUShortToShort(Stack& stack, const void* value)
{
	UShortT actualValue = *reinterpret_cast<const UShortT*>(value);
	ShortT converted = static_cast<ShortT>(actualValue);
	return stack.pushValue(TypeSymbol::getShortTypeSymbol(), &converted);
}

VariableData Runtime::convertUShortToInt(Stack& stack, const void* value)
{
	UShortT actualValue = *reinterpret_cast<const UShortT*>(value);
	IntT converted = static_cast<IntT>(actualValue);
	return stack.pushValue(TypeSymbol::getIntTypeSymbol(), &converted);
}

VariableData Runtime::convertUShortToUInt(Stack& stack, const void* value)
{
	UShortT actualValue = *reinterpret_cast<const UShortT*>(value);
	UIntT converted = static_cast<UIntT>(actualValue);
	return stack.pushValue(TypeSymbol::getUIntTypeSymbol(), &converted);
}

VariableData Runtime::convertUShortToLong(Stack& stack, const void* value)
{
	UShortT actualValue = *reinterpret_cast<const UShortT*>(value);
	LongT converted = static_cast<LongT>(actualValue);
	return stack.pushValue(TypeSymbol::getLongTypeSymbol(), &converted);
}

VariableData Runtime::convertUShortToULong(Stack& stack, const void* value)
{
	UShortT actualValue = *reinterpret_cast<const UShortT*>(value);
	ULongT converted = static_cast<ULongT>(actualValue);
	return stack.pushValue(TypeSymbol::getULongTypeSymbol(), &converted);
}
