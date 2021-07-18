#include "ConversionTable.h"

#include "PrimitivesConversions.h"

#include <Yac/Core/Errors/Exceptions/NotConvertibleToException.h>

using namespace Yac::Core;
using namespace Yac::Errors;
using namespace Yac::Runtime;

ConversionTable::ConversionTable(Stack& stack) 
	: _stack(&stack) 
{
	bind(TypeSymbol::getIntTypeSymbol(), TypeSymbol::getBoolTypeSymbol(), convertIntToBool);
}

void ConversionTable::bind(Cast cast, Converter converter) noexcept
{
	_table[cast] = converter;
}

void ConversionTable::bind(const TypeSymbol& fromType, const TypeSymbol& toType, Converter converter) noexcept
{
	Cast cast = Cast(fromType, toType);
	bind(cast, converter);
}

bool ConversionTable::contains(Cast cast) const noexcept
{
	auto it = _table.find(cast);
	return it != _table.end();
}

VariableData ConversionTable::convert(Cast cast, const void* value) const
{
	auto it = _table.find(cast);

	if (it == _table.end())
		throw NotConvertibleToException(cast);

	return it->second(*_stack, value);
}