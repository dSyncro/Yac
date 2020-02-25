#pragma once

#include "Command.h"

#include <Core/Repl/VariableTable.h>

namespace Yac::Core {

	using CommandCallback = void(*)(const std::vector<std::string>&, Yac::Core::VariableTable&);

	struct CommandHandler final {

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