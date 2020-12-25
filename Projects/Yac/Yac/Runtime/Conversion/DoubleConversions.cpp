#include "DoubleConversions.h"

using namespace Yac;
using namespace Yac::Core;
using namespace Yac::Runtime;

VariableData Runtime::convertDoubleToBool(Stack& stack, const void* value)
{
	double actualValue = *reinterpret_cast<const double*>(value);
	bool converted = actualValue != 0.0 ? true : false;
	return stack.pushValue(TypeSymbol::getBoolTypeSymbol(), &converted);
}

VariableData Runtime::convertDoubleToFloat(Stack& stack, const void* value)
{
	double actualValue = *reinterpret_cast<const double*>(value);
	float converted = static_cast<float>(actualValue);
	return stack.pushValue(TypeSymbol::getFloatTypeSymbol(), &converted);
}

VariableData Runtime::convertDoubleToShort(Stack& stack, const void* value)
{
	double actualValue = *reinterpret_cast<const double*>(value);
	ShortT converted = static_cast<ShortT>(actualValue);
	return stack.pushValue(TypeSymbol::getShortTypeSymbol(), &converted);
}

VariableData Runtime::convertDoubleToUShort(Stack& stack, const void* value)
{
	double actualValue = *reinterpret_cast<const double*>(value);
	UShortT converted = static_cast<UShortT>(actualValue);
	return stack.pushValue(TypeSymbol::getUShortTypeSymbol(), &converted);
}

VariableData Runtime::convertDoubleToInt(Stack& stack, const void* value)
{
	double actualValue = *reinterpret_cast<const double*>(value);
	IntT converted = static_cast<IntT>(actualValue);
	return stack.pushValue(TypeSymbol::getIntTypeSymbol(), &converted);
}

VariableData Runtime::convertDoubleToUInt(Stack& stack, const void* value)
{
	double actualValue = *reinterpret_cast<const double*>(value);
	UIntT converted = static_cast<UIntT>(actualValue);
	return stack.pushValue(TypeSymbol::getUIntTypeSymbol(), &converted);
}

VariableData Runtime::convertDoubleToLong(Stack& stack, const void* value)
{
	double actualValue = *reinterpret_cast<const double*>(value);
	LongT converted = static_cast<LongT>(actualValue);
	return stack.pushValue(TypeSymbol::getLongTypeSymbol(), &converted);
}

VariableData Runtime::convertDoubleToULong(Stack& stack, const void* value)
{
	double actualValue = *reinterpret_cast<const double*>(value);
	ULongT converted = static_cast<ULongT>(actualValue);
	return stack.pushValue(TypeSymbol::getULongTypeSymbol(), &converted);
}
