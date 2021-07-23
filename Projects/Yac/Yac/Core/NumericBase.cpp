#include "NumericBase.h"

#include "Base.h"

using namespace Yac;

std::string Yac::toString(NumericBase base)
{
	switch (base)
	{
		ENUM_ELEMENT_TO_STRING(NumericBase, Binary);
		ENUM_ELEMENT_TO_STRING(NumericBase, Decimal);
		ENUM_ELEMENT_TO_STRING(NumericBase, Hex);

		default: return "Unknown";
	}
}