#pragma once

#include <string>
#include <vector>

namespace Yac {
	namespace Core {

		using ParamList = const std::vector<std::string>&;

		struct Command {

		public:

			static Command Parse(std::string line) noexcept;

			inline std::string Name() const noexcept { return _cmd; }
			inline ParamList Parameters() const noexcept { return _params; }

		private:

			Command(std::string command, const std::vector<std::string> parameters);

			std::string _cmd;
			const std::vector<std::string> _params;
		};

	}
}