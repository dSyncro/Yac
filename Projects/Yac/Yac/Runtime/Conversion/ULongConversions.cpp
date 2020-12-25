#include "ULongConversions.h"

using namespace Yac;
using namespace Yac::Core;
using namespace Yac::Runtime;

VariableData Runtime::convertULongToBool(Stack& stack, const void* value)
{
	ULongT actualValue = *reinterpret_cast<const ULongT*>(value);
	bool converted = actualValue != 0 ? true : false;
	return stack.pushValue(TypeSymbol::getBoolTypeSymbol(), &converted);
}

VariableData Runtime::convertULongToFloat(Stack& stack, const void* value)
{
	ULongT actualValue = *reinterpret_cast<const ULongT*>(value);
	float converted = static_cast<float>(actualValue);
	return stack.pushValue(TypeSymbol::getFloatTypeSymbol(), &converted);
}

VariableData Runtime::convertULongToDouble(Stack& stack, const void* value)
{
	ULongT actualValue = *reinterpret_cast<const ULongT*>(value);
	double converted = static_cast<double>(actualValue);
	return stack.pushValue(TypeSymbol::getDoubleTypeSymbol(), &converted);
}

VariableData Runtime::convertULongToShort(Stack& stack, const void* value)
{
	ULongT actualValue = *reinterpret_cast<const ULongT*>(value);
	ShortT converted = static_cast<ShortT>(actualValue);
	return stack.pushValue(TypeSymbol::getShortTypeSymbol(), &converted);
}

VariableData Runtime::convertULongToUShort(Stack& stack, const void* value)
{
	ULongT actualValue = *reinterpret_cast<const ULongT*>(value);
	UShortT converted = static_cast<UShortT>(actualValue);
	return stack.pushValue(TypeSymbol::getUShortTypeSymbol(), &converted);
}

VariableData Runtime::convertULongToInt(Stack& stack, const void* value)
{
	ULongT actualValue = *reinterpret_cast<const ULongT*>(value);
	IntT converted = static_cast<IntT>(actualValue);
	return stack.pushValue(TypeSymbol::getIntTypeSymbol(), &converted);
}

VariableData Runtime::convertULongToUInt(Stack& stack, const void* value)
{
	ULongT actualValue = *reinterpret_cast<const ULongT*>(value);
	UIntT converted = static_cast<UIntT>(actualValue);
	return stack.pushValue(TypeSymbol::getUIntTypeSymbol(), &converted);
}

VariableData Runtime::convertULongToLong(Stack& stack, const void* value)
{
	ULongT actualValue = *reinterpret_cast<const ULongT*>(value);
	LongT converted = static_cast<LongT>(actualValue);
	return stack.pushValue(TypeSymbol::getLongTypeSymbol(), &converted);
}
