#pragma once

#include <string>

namespace Yac::Syntax {

	enum class NumericType {
		Int,
		UInt,
		Float,
		Double
	};

	// Private Members
	namespace {

		const char* NumericTypeString[] = {
			"Int",
			"UInt",
			"Float",
			"Double",
		};

	}

	inline std::string toString(NumericType type)
	{
		return NumericTypeString[static_cast<UIntT>(type)];
	}
}