#pragma once

#include "Command.h"

#include <Yac/Core/Repl/VariableTable.h>

namespace Yac {

	using CommandCallback = void(*)(const std::vector<std::string>&, Yac::VariableTable&);

	struct CommandHandler final {

	public:

		CommandHandler(std::string command, CommandCallback callback);

		bool cast(const Command& command, VariableTable& variables) const noexcept;

		void invoke(const std::vector<std::string>& parameters, VariableTable& variables) const noexcept { _callback(parameters, variables); }

		const std::string& getCommandName() const noexcept { return _cmd; }

	private:

		std::string _cmd;
		CommandCallback _callback;

	};
}