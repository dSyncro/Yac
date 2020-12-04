#include "NameTable.h"

using namespace Yac::DataTypes;
using namespace Yac::Syntax;

bool NameTable::hasBeenDeclared(const TypeSymbol& symbol) const noexcept
{
	return _types.contains(symbol);
}

bool NameTable::hasBeenDeclared(const Conversion& conversion) const noexcept
{
	return _converters.contains(conversion);
}

void NameTable::record(const TypeSymbol& symbol) noexcept
{
	_types.add(symbol);
}

void NameTable::record(const Conversion& conversion, ConversionHandler handler) noexcept
{
	_converters.record(conversion, handler);
}