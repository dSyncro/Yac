#pragma once

#include <exception>

namespace Yac::Errors {

	struct ObjectConversionException : std::exception {

		const char* what() const noexcept override
		{
			// Placeholder, better struct has to be written
			return "Cannot convert this object to Type";
		}

	};

}