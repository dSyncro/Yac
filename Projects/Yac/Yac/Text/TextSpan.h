#pragma once

#include <Yac/Core/Primitives.h>

namespace Yac::Text {

	struct TextSpan final {

	public:

		TextSpan(UIntT start, UIntT length) : _start(start), _length(length) {}

		UIntT getStart() const noexcept { return _start; }
		UIntT getLength() const noexcept { return _length; }
		UIntT getEnd() const noexcept { return _start + _length; }

		std::string toString() const noexcept { return "{" + std::to_string(_start) + ", " + std::to_string(_length) + "}"; }

	private:

		UIntT _start = 0, _length = 0;
	};
}