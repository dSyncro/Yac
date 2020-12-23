#pragma once

#include <exception>

#include <Yac/Runtime/Cast.h>

namespace Yac::Errors {

	struct NotConvertibleToException : std::exception {

	public:

		NotConvertibleToException(Runtime::Cast cast)
		{
			_msg = "Cannot convert from <" + cast.getFromType().getName() + "> to <" + cast.getToType().getName() + ">.";
		}

		const char* what() const noexcept override { return _msg.c_str(); }

	private:

		std::string _msg;

	};

}