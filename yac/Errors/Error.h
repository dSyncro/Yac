#pragma once

#include <string>

#include <yac/Text/TextSpan.h>

namespace Yac {
	namespace Errors {

		struct Error {

		public:

			Error(std::string message, Yac::Text::TextSpan span) : _msg(message), _span(span) {}

			inline Yac::Text::TextSpan span() const noexcept { return _span; }
			inline std::string message() const noexcept { return _msg; }

			std::string ToString() const noexcept { return _span.ToString() + ": " + _msg; }

		private:

			Yac::Text::TextSpan _span;
			std::string _msg;
		};

	}
}