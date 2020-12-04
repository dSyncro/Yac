#pragma once

#include <exception>

#include <Yac/DataTypes/Types/TypeSymbol.h>

namespace Yac::Errors {

	struct WrongConverterException : std::exception {

	public:

		WrongConverterException(const Yac::DataTypes::TypeSymbol& objectType, const Yac::DataTypes::TypeSymbol& fromType, const Yac::DataTypes::TypeSymbol& toType)
		{
			_msg = "Cannot convert object of type <";
			_msg.append(objectType.getName());
			_msg.append("> with a {");
			_msg.append(fromType.getName());
			_msg.append(" -> ");
			_msg.append(toType.getName());
			_msg.append("} conversion");
		}

		const char* what() const noexcept override { return _msg.c_str(); }

	private:

		std::string _msg;

	};

}