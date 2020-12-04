#pragma once

#include <string>
#include <vector>

namespace Yac::Core {

	using ParameterList = std::vector<std::string>;

	struct Command final {

	public:

		static Command parse(const std::string& line) noexcept;

		const std::string& getName() const noexcept { return _cmd; }
		const ParameterList& getParameters() const noexcept { return _params; }

	private:

		Command(const std::string& command, const ParameterList& parameters);

		std::string _cmd;
		ParameterList _params;
	};

}