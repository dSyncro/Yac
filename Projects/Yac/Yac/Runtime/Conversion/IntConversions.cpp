#include "IntConversions.h"

using namespace Yac;
using namespace Yac::Core;
using namespace Yac::Runtime;

VariableData Runtime::convertIntToBool(Stack& stack, const void* value)
{
	IntT actualValue = *reinterpret_cast<const IntT*>(value);
	bool converted = actualValue != 0 ? true : false;
	return stack.pushValue(TypeSymbol::getBoolTypeSymbol(), &converted);
}

VariableData Runtime::convertIntToFloat(Stack& stack, const void* value)
{
	IntT actualValue = *reinterpret_cast<const IntT*>(value);
	float converted = static_cast<float>(actualValue);
	return stack.pushValue(TypeSymbol::getFloatTypeSymbol(), &converted);
}

VariableData Runtime::convertIntToDouble(Stack& stack, const void* value)
{
	IntT actualValue = *reinterpret_cast<const IntT*>(value);
	double converted = static_cast<double>(actualValue);
	return stack.pushValue(TypeSymbol::getDoubleTypeSymbol(), &converted);
}

VariableData Runtime::convertIntToShort(Stack& stack, const void* value)
{
	IntT actualValue = *reinterpret_cast<const IntT*>(value);
	ShortT converted = static_cast<ShortT>(actualValue);
	return stack.pushValue(TypeSymbol::getShortTypeSymbol(), &converted);
}

VariableData Runtime::convertIntToUShort(Stack& stack, const void* value)
{
	IntT actualValue = *reinterpret_cast<const IntT*>(value);
	UShortT converted = static_cast<UShortT>(actualValue);
	return stack.pushValue(TypeSymbol::getUShortTypeSymbol(), &converted);
}

VariableData Runtime::convertIntToUInt(Stack& stack, const void* value)
{
	IntT actualValue = *reinterpret_cast<const IntT*>(value);
	UIntT converted = static_cast<UIntT>(actualValue);
	return stack.pushValue(TypeSymbol::getUIntTypeSymbol(), &converted);
}

VariableData Runtime::convertIntToLong(Stack& stack, const void* value)
{
	IntT actualValue = *reinterpret_cast<const IntT*>(value);
	LongT converted = static_cast<LongT>(actualValue);
	return stack.pushValue(TypeSymbol::getLongTypeSymbol(), &converted);
}

VariableData Runtime::convertIntToULong(Stack& stack, const void* value)
{
	IntT actualValue = *reinterpret_cast<const IntT*>(value);
	ULongT converted = static_cast<ULongT>(actualValue);
	return stack.pushValue(TypeSymbol::getULongTypeSymbol(), &converted);
}