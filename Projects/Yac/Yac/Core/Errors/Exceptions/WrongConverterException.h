#pragma once

#include <exception>

#include <Yac/Core/Types/TypeSymbol.h>

namespace Yac::Errors {

	struct WrongConverterException : std::exception {

	public:

		WrongConverterException(const DataTypes::TypeSymbol& objectType, const DataTypes::TypeSymbol& fromType, const DataTypes::TypeSymbol& toType)
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