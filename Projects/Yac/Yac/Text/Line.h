#pragma once

#include "TextSpan.h"

#include <string>

namespace Yac::Text {

	struct Line final {

	public:

		Line(const std::string& text, TextSpan span)
			: _text(text), _span(span) { }

		char operator [](UIntT index) const { return _text[index]; }

		const std::string& getText() const noexcept { return _text; }

		const TextSpan& getSpan() const noexcept { return _span; }
		UIntT getStart() const noexcept { return _span.getStart(); }
		UIntT getLength() const noexcept { return _span.getLength(); }
		UIntT getEnd() const noexcept { return _span.getEnd(); }

		std::string getSubstring(UIntT start = 0, UIntT length = 0xFFFFFFFF) const noexcept
		{
			return _text.substr(start, length);
		}

	private:

		std::string _text;
		TextSpan _span;
	};
}