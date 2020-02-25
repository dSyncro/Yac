#pragma once

#include "CommandHandler.h"

#include <Core/Repl/VariableTable.h>

namespace Yac::Core {

	class CommandTable final {

	public:

		CommandTable() {}
		CommandTable(std::vector<CommandHandler> handlers);

		void Invoke(const Command& command, VariableTable& variables) const noexcept;

		void InvokeAll(const Command& command, VariableTable& variables) const noexcept;

		inline void Add(const CommandHandler& handler) noexcept { _handlers.push_back(handler); }

		void Register(const CommandHandler& handler) noexcept;

		bool ContainsHandlerFor(const std::string& command) const noexcept;

		inline void Clear() noexcept { _handlers.clear(); }

	private:

		std::vector<CommandHandler> _handlers;
	};

}