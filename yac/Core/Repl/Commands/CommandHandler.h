#pragma once

#include "Command.h"

#include <yac/Core/Repl/VariableTable.h>

using CommandCallback = void(*)(const std::vector<std::string>&, Yac::Core::VariableTable&);

namespace Yac {
	namespace Core {

		struct CommandHandler {

		public:

			CommandHandler(std::string command, CommandCallback callback);

			bool Cast(const Command& command, VariableTable& variables) const noexcept;

			inline void Invoke(ParamList parameters, VariableTable& variables) const noexcept { _callback(parameters, variables); }

			inline const std::string& CommandName() const noexcept { return _cmd; }

		private:

			std::string _cmd;
			CommandCallback _callback;

		};

	}
}