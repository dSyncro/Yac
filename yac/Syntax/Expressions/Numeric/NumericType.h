#pragma once

namespace Yac {
	namespace Syntax {

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

		inline std::string ToString(NumericType type)
		{
			return NumericTypeString[(unsigned int)type];
		}

	}
}