#include "TypeSymbol.h"

using namespace Yac;

const TypeSymbol& TypeSymbol::getInvalidTypeSymbol() noexcept
{
	static TypeSymbol type = "null";
	return type;
}