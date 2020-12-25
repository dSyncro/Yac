#pragma once

#include <exception>
#include <string>

namespace Yac::Errors {

	struct VariableAlreadyDeclaredException : std::exception {

	public:

		VariableAlreadyDeclaredException(const std::string& name)
		{
			_msg = "Variable `" + name + "` was already declared in this scope.";
		}

		const char* what() const noexcept override { return _msg.c_str(); }

	private:

		std::string _msg;

	};

}