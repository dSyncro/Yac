#pragma once

namespace Yac {
	namespace Text {

		struct TextSpan {

		public:

			TextSpan(unsigned int start, unsigned int length) : _start(start), _length(length) {}
			TextSpan() {}

			inline unsigned int start() const noexcept { return _start; }
			inline unsigned int length() const noexcept { return _length; }
			inline unsigned int end() const noexcept { return _start + _length; }

			inline std::string ToString() { return "{" + std::to_string(_start) + ", " + std::to_string(_length) + "}"; }

		private:

			unsigned int _start = 0, _length = 0;
		};

	}
}