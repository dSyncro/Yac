#pragma once

#include <string>

#include <Text/TextSpan.h>

namespace Yac::Errors {

	struct Error {

	public:

		Error(const std::string& message, Yac::Text::TextSpan span) : _msg(message), _span(span) {}

		Yac::Text::TextSpan getSpan() const noexcept { return _span; }
		const std::string& getMessage() const noexcept { return _msg; }

		std::string toString() const noexcept { return _span.ToString() + ": " + _msg; }

	private:

		Yac::Text::TextSpan _span;
		std::string _msg;
	};
}