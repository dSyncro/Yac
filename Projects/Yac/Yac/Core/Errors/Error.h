#pragma once

#include <string>

#include <Yac/Core/Text/TextSpan.h>

namespace Yac::Errors {

	struct Error {

	public:

		Error(const std::string& message, TextSpan span) : _msg(message), _span(span) {}

		TextSpan getSpan() const noexcept { return _span; }
		const std::string& getMessage() const noexcept { return _msg; }

		std::string toString() const noexcept { return _span.toString() + ": " + _msg; }

	private:

		TextSpan _span;
		std::string _msg;
	};
}