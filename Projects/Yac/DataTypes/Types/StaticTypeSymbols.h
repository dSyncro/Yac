#pragma once

#include "TypeSymbol.h"

namespace Yac::DataTypes {

	const TypeSymbol ObjectTypeSymbol = TypeSymbol("object");

	const TypeSymbol BoolTypeSymbol = TypeSymbol("bool");

	const TypeSymbol DoubleTypeSymbol = TypeSymbol("double");
	const TypeSymbol FloatTypeSymbol = TypeSymbol("float");

	const TypeSymbol IntTypeSymbol = TypeSymbol("int");
	const TypeSymbol UIntTypeSymbol = TypeSymbol("uint");

	const TypeSymbol StringTypeSymbol = TypeSymbol("string");

	const TypeSymbol VoidTypeSymbol = TypeSymbol("void");
}