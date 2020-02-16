#pragma once

#include "Command.h"

using CommandCallback = void(*)(const std::vector<std::string>&);

namespace Yac {
	namespace Core {

		struct CommandHandler {

		public:

			CommandHandler(std::string command, CommandCallback callback);

			bool Cast(const Command& command) const noexcept;

			inline void Invoke(ParamList parameters) const noexcept { _callback(parameters); }

			inline const std::string& CommandName() const noexcept { return _cmd; }

		private:

			std::string _cmd;
			CommandCallback _callback;

		};

	}
}