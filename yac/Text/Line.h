#pragma once

#include "TextSpan.h"

#include <string>

namespace Yac {
	namespace Text {

		struct Line {

		public:

			Line(std::string string, TextSpan span)
				: _string(string), _span(span)
			{
			}

			char operator [](unsigned int index) const { return _string[index]; }

			inline const std::string& text() const noexcept { return _string; }

			inline const TextSpan& span() const noexcept { return _span; }
			inline unsigned int start() const noexcept { return _span.start(); }
			inline unsigned int length() const noexcept { return _span.length(); }
			inline unsigned int end() const noexcept { return _span.end(); }

			std::string substr(unsigned int start = 0, unsigned int length = 0xFFFFFFFF) const noexcept { return _string.substr(start, length); }

		private:

			std::string _string;
			TextSpan _span;
		};

	}
}