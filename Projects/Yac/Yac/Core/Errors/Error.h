#pragma once

#include <string>

#include <Yac/Core/Text/TextSpan.h>

namespace Yac::Errors {

	struct Error {

	public:

		Error(const std::string& message, Text::TextSpan span) : _msg(message), _span(span) {}

		Text::TextSpan getSpan() const noexcept { return _span; }
		const std::string& getMessage() const noexcept { return _msg; }

		std::string toString() const noexcept { return _span.toString() + ": " + _msg; }

	private:

		Text::TextSpan _span;
		std::string _msg;
	};
}