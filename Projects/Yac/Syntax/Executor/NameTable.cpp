#include "NameTable.h"

using namespace Yac::DataTypes;
using namespace Yac::Syntax;

bool NameTable::HasBeenDeclared(const TypeSymbol& symbol) const noexcept
{
	return _types.contains(symbol);
}

bool NameTable::HasBeenDeclared(const Conversion& conversion) const noexcept
{
	return _converters.Contains(conversion);
}

void NameTable::Register(const TypeSymbol& symbol) noexcept
{
	_types.add(symbol);
}

void NameTable::Register(const Conversion& conversion, ConversionHandler handler) noexcept
{
	_converters.Register(conversion, handler);
}