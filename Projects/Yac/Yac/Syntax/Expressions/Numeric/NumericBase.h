#pragma once

#include <string>

namespace Yac::Syntax {

	enum class NumericBase {
		Binary = 2,
		Decimal = 10,
		Hex = 16,
	};

	inline std::string toString(NumericBase base)
	{
		switch (base)
		{
			case NumericBase::Binary: return "Binary";
			case NumericBase::Decimal: return "Decimal";
			case NumericBase::Hex: return "Hex";

			default: return "Unknown";
		}
	}

}