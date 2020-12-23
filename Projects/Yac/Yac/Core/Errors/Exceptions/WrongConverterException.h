#pragma once

#include <exception>

#include <Yac/Core/Types/TypeSymbol.h>

namespace Yac::Errors {

	struct WrongConverterException : std::exception {

	public:

		WrongConverterException(const Core::TypeSymbol& objectType, const Core::TypeSymbol& fromType, const Core::TypeSymbol& toType)
		{
			_msg = "Cannot convert object of type <" 
				+ objectType.getName() + "> with a {" 
				+ fromType.getName() 
				+ " -> " + toType.getName() 
				+ "} conversion";
		}

		const char* what() const noexcept override { return _msg.c_str(); }

	private:

		std::string _msg;

	};

}