#include "UIntConversions.h"

using namespace Yac;
using namespace Yac::Core;
using namespace Yac::Runtime;

VariableData Runtime::convertUIntToBool(Stack& stack, const void* value)
{
	UIntT actualValue = *reinterpret_cast<const UIntT*>(value);
	bool converted = actualValue != 0 ? true : false;
	return stack.pushValue(TypeSymbol::getBoolTypeSymbol(), &converted);
}

VariableData Runtime::convertUIntToFloat(Stack& stack, const void* value)
{
	UIntT actualValue = *reinterpret_cast<const UIntT*>(value);
	float converted = static_cast<float>(actualValue);
	return stack.pushValue(TypeSymbol::getFloatTypeSymbol(), &converted);
}

VariableData Runtime::convertUIntToDouble(Stack& stack, const void* value)
{
	UIntT actualValue = *reinterpret_cast<const UIntT*>(value);
	double converted = static_cast<double>(actualValue);
	return stack.pushValue(TypeSymbol::getDoubleTypeSymbol(), &converted);
}

VariableData Runtime::convertUIntToShort(Stack& stack, const void* value)
{
	UIntT actualValue = *reinterpret_cast<const UIntT*>(value);
	ShortT converted = static_cast<ShortT>(actualValue);
	return stack.pushValue(TypeSymbol::getShortTypeSymbol(), &converted);
}

VariableData Runtime::convertUIntToUShort(Stack& stack, const void* value)
{
	UIntT actualValue = *reinterpret_cast<const UIntT*>(value);
	UShortT converted = static_cast<UShortT>(actualValue);
	return stack.pushValue(TypeSymbol::getUShortTypeSymbol(), &converted);
}

VariableData Runtime::convertUIntToInt(Stack& stack, const void* value)
{
	UIntT actualValue = *reinterpret_cast<const UIntT*>(value);
	IntT converted = static_cast<IntT>(actualValue);
	return stack.pushValue(TypeSymbol::getIntTypeSymbol(), &converted);
}

VariableData Runtime::convertUIntToLong(Stack& stack, const void* value)
{
	UIntT actualValue = *reinterpret_cast<const UIntT*>(value);
	LongT converted = static_cast<LongT>(actualValue);
	return stack.pushValue(TypeSymbol::getLongTypeSymbol(), &converted);
}

VariableData Runtime::convertUIntToULong(Stack& stack, const void* value)
{
	UIntT actualValue = *reinterpret_cast<const UIntT*>(value);
	ULongT converted = static_cast<ULongT>(actualValue);
	return stack.pushValue(TypeSymbol::getULongTypeSymbol(), &converted);
}
