#include "NumericType.h"

#include <Yac/Core/Base.h>

using namespace Yac;

std::string Yac::toString(NumericType type)
{
	switch(type)
	{
		ENUM_ELEMENT_TO_STRING(NumericType, Int);
		ENUM_ELEMENT_TO_STRING(NumericType, UInt);
		ENUM_ELEMENT_TO_STRING(NumericType, Float);
		ENUM_ELEMENT_TO_STRING(NumericType, Double);
		default: return "Unknown";
	}
}