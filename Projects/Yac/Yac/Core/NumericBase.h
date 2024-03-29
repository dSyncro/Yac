#pragma once

#include <string>

namespace Yac {

	enum class NumericBase {
		Binary = 2,
		Decimal = 10,
		Hex = 16,
	};

	std::string toString(NumericBase base);

}