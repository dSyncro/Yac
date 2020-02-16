#pragma once

namespace Yac {
	namespace Text {

		struct TextSpan {

		public:

			TextSpan(std::size_t start, std::size_t length) : _start(start), _length(length) {}

			inline std::size_t start() const noexcept { return _start; }
			inline std::size_t length() const noexcept { return _length; }
			inline std::size_t end() const noexcept { return _start + _length; }

			inline std::string ToString() const noexcept { return "{" + std::to_string(_start) + ", " + std::to_string(_length) + "}"; }

		private:

			std::size_t _start = 0, _length = 0;
		};

	}
}