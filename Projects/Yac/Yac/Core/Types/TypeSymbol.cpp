#include "TypeSymbol.h"

using namespace Yac;
using namespace Yac::Core;

const TypeSymbol& TypeSymbol::getByteTypeSymbol()
{
	static TypeSymbol symbol = TypeSymbol("byte", 1);
	return symbol;
}

const TypeSymbol& TypeSymbol::getBoolTypeSymbol()
{
	static TypeSymbol symbol = TypeSymbol("bool", 1);
	return symbol;
}

const TypeSymbol& TypeSymbol::getCharTypeSymbol()
{
	static TypeSymbol symbol = TypeSymbol("char", 1);
	return symbol;
}

const TypeSymbol& TypeSymbol::getDoubleTypeSymbol()
{
	static TypeSymbol symbol = TypeSymbol("double", 8);
	return symbol;
}

const TypeSymbol& TypeSymbol::getFloatTypeSymbol()
{
	static TypeSymbol symbol = TypeSymbol("float", 4);
	return symbol;
}

const TypeSymbol& TypeSymbol::getShortTypeSymbol()
{
	static TypeSymbol symbol = TypeSymbol("short", 2);
	return symbol;
}

const TypeSymbol& TypeSymbol::getUShortTypeSymbol()
{
	static TypeSymbol symbol = TypeSymbol("ushort", 2);
	return symbol;
}

const TypeSymbol& TypeSymbol::getIntTypeSymbol()
{
	static TypeSymbol symbol = TypeSymbol("int", 4);
	return symbol;
}

const TypeSymbol& TypeSymbol::getUIntTypeSymbol()
{
	static TypeSymbol symbol = TypeSymbol("uint", 4);
	return symbol;
}

const TypeSymbol& TypeSymbol::getLongTypeSymbol()
{
	static TypeSymbol symbol = TypeSymbol("long", 8);
	return symbol;
}

const TypeSymbol& TypeSymbol::getULongTypeSymbol()
{
	static TypeSymbol symbol = TypeSymbol("ulong", 8);
	return symbol;
}

const TypeSymbol& TypeSymbol::getObjectTypeSymbol()
{
	static TypeSymbol symbol = TypeSymbol("object", 1);
	return symbol;
}

const TypeSymbol& TypeSymbol::getStringTypeSymbol()
{
	static TypeSymbol symbol = TypeSymbol("string", sizeof(std::string));
	return symbol;
}

const TypeSymbol& TypeSymbol::getVoidTypeSymbol()
{
	static TypeSymbol symbol = TypeSymbol();
	return symbol;
}

template <>
const TypeSymbol& Core::toTypeSymbol<ByteT>()
{
	return TypeSymbol::getByteTypeSymbol();
}

template <>
const TypeSymbol& Core::toTypeSymbol<bool>()
{
	return TypeSymbol::getBoolTypeSymbol();
}

template <>
const TypeSymbol& Core::toTypeSymbol<char>()
{
	return TypeSymbol::getCharTypeSymbol();
}

template <>
const TypeSymbol& Core::toTypeSymbol<double>()
{
	return TypeSymbol::getDoubleTypeSymbol();
}

template <>
const TypeSymbol& Core::toTypeSymbol<float>()
{
	return TypeSymbol::getFloatTypeSymbol();
}

template <>
const TypeSymbol& Core::toTypeSymbol<ShortT>()
{
	return TypeSymbol::getShortTypeSymbol();
}

template <>
const TypeSymbol& Core::toTypeSymbol<UShortT>()
{
	return TypeSymbol::getUShortTypeSymbol();
}

template <>
const TypeSymbol& Core::toTypeSymbol<IntT>()
{
	return TypeSymbol::getIntTypeSymbol();
}

template <>
const TypeSymbol& Core::toTypeSymbol<UIntT>()
{
	return TypeSymbol::getUIntTypeSymbol();
}

template <>
const TypeSymbol& Core::toTypeSymbol<LongT>()
{
	return TypeSymbol::getLongTypeSymbol();
}

template <>
const TypeSymbol& Core::toTypeSymbol<ULongT>()
{
	return TypeSymbol::getULongTypeSymbol();
}