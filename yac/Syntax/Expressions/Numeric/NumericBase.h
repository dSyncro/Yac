#pragma once

#include <string>

namespace Yac {
	namespace Syntax {

		enum class NumericBase {
			Binary = 2,
			Decimal = 10,
			Hex = 16,
		};

		inline std::string ToString(NumericBase base)
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
}