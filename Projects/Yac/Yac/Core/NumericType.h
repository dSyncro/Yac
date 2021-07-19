#pragma once

#include <string>

namespace Yac {

	enum class NumericType {
		Int,
		UInt,
		Float,
		Double
	};

	std::string toString(NumericType type);
}