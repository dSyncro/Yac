#pragma once

#include <exception>
#include <string>

namespace Yac::Errors {

	struct VariableNotDeclaredException : std::exception {

	public:

		VariableNotDeclaredException(const std::string& name)
		{
			_msg = "Variable `" + name + "` was not declared.";
		}

		const char* what() const noexcept override { return _msg.c_str(); }

	private:

		std::string _msg;

	};

}