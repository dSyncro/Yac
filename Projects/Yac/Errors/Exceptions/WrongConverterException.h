#pragma once

#include <exception>

#include <DataTypes/TypeSymbol.h>

namespace Yac::Errors {

	struct WrongConverterException : std::exception {

	public:

		WrongConverterException(const Yac::DataTypes::TypeSymbol& objectType, const Yac::DataTypes::TypeSymbol& fromType, const Yac::DataTypes::TypeSymbol& toType)
		{
			_msg = "Cannot convert object of type <";
			_msg.append(objectType.name());
			_msg.append("> with a {");
			_msg.append(fromType.name());
			_msg.append(" -> ");
			_msg.append(toType.name());
			_msg.append("} conversion");
		}

		inline const char* what() const noexcept { return _msg.c_str(); }

	private:

		std::string _msg;

	};

}