#pragma once

#include "TextSpan.h"

#include <string>

namespace Yac::Text {

	struct Line final {

	public:

		Line(std::string string, TextSpan span)
			: _string(string), _span(span)
		{
		}

		char operator [](unsigned int index) const { return _string[index]; }

		inline const std::string& text() const noexcept { return _string; }

		inline const TextSpan& span() const noexcept { return _span; }
		inline std::size_t start() const noexcept { return _span.start(); }
		inline std::size_t length() const noexcept { return _span.length(); }
		inline std::size_t end() const noexcept { return _span.end(); }

		std::string substr(std::size_t start = 0, std::size_t length = 0xFFFFFFFF)
			const noexcept
		{
			return _string.substr(start, length);
		}

	private:

		std::string _string;
		TextSpan _span;
	};
}