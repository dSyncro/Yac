#include "FloatConversions.h"

using namespace Yac;
using namespace Yac::Core;
using namespace Yac::Runtime;

VariableData Runtime::convertFloatToBool(Stack& stack, const void* value)
{
	float actualValue = *reinterpret_cast<const float*>(value);
	bool converted = actualValue != 0 ? true : false;
	return stack.pushValue(TypeSymbol::getBoolTypeSymbol(), &converted);
}

VariableData Runtime::convertFloatToDouble(Stack& stack, const void* value)
{
	float actualValue = *reinterpret_cast<const float*>(value);
	double converted = static_cast<double>(actualValue);
	return stack.pushValue(TypeSymbol::getDoubleTypeSymbol(), &converted);
}

VariableData Runtime::convertFloatToShort(Stack& stack, const void* value)
{
	float actualValue = *reinterpret_cast<const float*>(value);
	ShortT converted = static_cast<ShortT>(actualValue);
	return stack.pushValue(TypeSymbol::getShortTypeSymbol(), &converted);
}

VariableData Runtime::convertFloatToUShort(Stack& stack, const void* value)
{
	float actualValue = *reinterpret_cast<const float*>(value);
	UShortT converted = static_cast<UShortT>(actualValue);
	return stack.pushValue(TypeSymbol::getUShortTypeSymbol(), &converted);
}

VariableData Yac::Runtime::convertFloatToInt(Stack& stack, const void* value)
{
	float actualValue = *reinterpret_cast<const float*>(value);
	IntT converted = static_cast<IntT>(actualValue);
	return stack.pushValue(TypeSymbol::getIntTypeSymbol(), &converted);
}

VariableData Runtime::convertFloatToUInt(Stack& stack, const void* value)
{
	float actualValue = *reinterpret_cast<const float*>(value);
	UIntT converted = static_cast<UIntT>(actualValue);
	return stack.pushValue(TypeSymbol::getIntTypeSymbol(), &converted);
}

VariableData Runtime::convertFloatToLong(Stack& stack, const void* value)
{
	float actualValue = *reinterpret_cast<const float*>(value);
	LongT converted = static_cast<LongT>(actualValue);
	return stack.pushValue(TypeSymbol::getShortTypeSymbol(), &converted);
}

VariableData Runtime::convertFloatToULong(Stack& stack, const void* value)
{
	float actualValue = *reinterpret_cast<const float*>(value);
	ULongT converted = static_cast<ULongT>(actualValue);
	return stack.pushValue(TypeSymbol::getShortTypeSymbol(), &converted);
}