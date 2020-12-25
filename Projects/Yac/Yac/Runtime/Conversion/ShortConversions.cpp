#include "ShortConversions.h"

using namespace Yac;
using namespace Yac::Core;
using namespace Yac::Runtime;

VariableData Runtime::convertShortToBool(Stack& stack, const void* value)
{
	ShortT actualValue = *reinterpret_cast<const ShortT*>(value);
	bool converted = actualValue != 0 ? true : false;
	return stack.pushValue(TypeSymbol::getShortTypeSymbol(), &converted);
}

VariableData Runtime::convertShortToFloat(Stack& stack, const void* value)
{
	ShortT actualValue = *reinterpret_cast<const ShortT*>(value);
	float converted = static_cast<float>(actualValue);
	return stack.pushValue(TypeSymbol::getFloatTypeSymbol(), &converted);
}

VariableData Runtime::convertShortToDouble(Stack& stack, const void* value)
{
	ShortT actualValue = *reinterpret_cast<const ShortT*>(value);
	double converted = static_cast<double>(actualValue);
	return stack.pushValue(TypeSymbol::getDoubleTypeSymbol(), &converted);
}

VariableData Runtime::convertShortToUShort(Stack& stack, const void* value)
{
	ShortT actualValue = *reinterpret_cast<const ShortT*>(value);
	UShortT converted = static_cast<UShortT>(actualValue);
	return stack.pushValue(TypeSymbol::getUShortTypeSymbol(), &converted);
}

VariableData Runtime::convertShortToInt(Stack& stack, const void* value)
{
	ShortT actualValue = *reinterpret_cast<const ShortT*>(value);
	IntT converted = static_cast<IntT>(actualValue);
	return stack.pushValue(TypeSymbol::getIntTypeSymbol(), &converted);
}

VariableData Runtime::convertShortToUInt(Stack& stack, const void* value)
{
	ShortT actualValue = *reinterpret_cast<const ShortT*>(value);
	UIntT converted = static_cast<UIntT>(actualValue);
	return stack.pushValue(TypeSymbol::getUIntTypeSymbol(), &converted);
}

VariableData Runtime::convertShortToLong(Stack& stack, const void* value)
{
	ShortT actualValue = *reinterpret_cast<const ShortT*>(value);
	LongT converted = static_cast<LongT>(actualValue);
	return stack.pushValue(TypeSymbol::getLongTypeSymbol(), &converted);
}

VariableData Runtime::convertShortToULong(Stack& stack, const void* value)
{
	ShortT actualValue = *reinterpret_cast<const ShortT*>(value);
	ULongT converted = static_cast<ULongT>(actualValue);
	return stack.pushValue(TypeSymbol::getULongTypeSymbol(), &converted);
}
