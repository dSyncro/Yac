#pragma once

#include "CommandHandler.h"

#include <Core/Repl/VariableTable.h>

namespace Yac::Core {

	class CommandTable final {

	public:

		CommandTable() {}
		CommandTable(std::vector<CommandHandler> handlers);

		void invoke(const Command& command, VariableTable& variables) const noexcept;

		void invokeAll(const Command& command, VariableTable& variables) const noexcept;

		void push(const CommandHandler& handler) noexcept { _handlers.push_back(handler); }

		void add(const CommandHandler& handler) noexcept;

		bool containsHandlerFor(const std::string& command) const noexcept;

		void clear() noexcept { _handlers.clear(); }

	private:

		std::vector<CommandHandler> _handlers;
	};

}