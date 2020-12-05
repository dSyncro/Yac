#include "NameTable.h"

using namespace Yac::Core;
using namespace Yac::Runtime;

bool NameTable::hasBeenDeclared(const TypeSymbol& symbol) const noexcept
{
	return _types.contains(symbol);
}

bool NameTable::hasBeenDeclared(Cast cast) const noexcept
{
	return _converters.contains(cast);
}

void NameTable::record(const TypeSymbol& symbol) noexcept
{
	_types.add(symbol);
}

void NameTable::record(Cast cast, Converter converter) noexcept
{
	_converters.record(cast, converter);
}