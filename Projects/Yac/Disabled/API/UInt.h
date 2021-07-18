#pragma once

#include <limits>

#include "Object.h"
#include "String.h"

#include <Yac/Core/Primitives.h>
#include <string>

namespace Yac::Api {

	struct UInt final : public Object {

	public:

		constexpr UInt(std::uint32_t n = 0) : _n(n) {}

		operator std::uint32_t() const { return _n; }

		UInt operator ++(int) { UInt temp = *this; ++(*this); return temp; }
		UInt& operator ++() { ++_n; return *this; }

		UInt operator --(int) { UInt temp = *this; --(*this); return temp; }
		UInt& operator --() { --_n; return *this; }

		constexpr static UInt maxValue() noexcept { return std::numeric_limits<std::uint32_t>::max(); }
		constexpr static UInt minValue() noexcept { return std::numeric_limits<std::uint32_t>::min(); }

		constexpr static UInt infinity() noexcept { return maxValue(); }

		// static UInt parse(const String& string) noexcept;
		// static bool tryParse(const String& string, UInt& out) noexcept;

		String toString() const noexcept { return std::to_string(_n); }

	private:

		std::uint32_t _n;
	};

}