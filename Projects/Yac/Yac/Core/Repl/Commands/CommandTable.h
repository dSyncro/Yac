#pragma once

#include "CommandHandler.h"

#include <Yac/Core/Repl/VariableTable.h>

namespace Yac {

	class CommandTable final {

	public:

		CommandTable() {}
		CommandTable(const std::vector<CommandHandler>& handlers);

		void invoke(const Command& command, VariableTable& variables) const noexcept;

		void invokeAll(const Command& command, VariableTable& variables) const noexcept;

		void push(const CommandHandler& handler) noexcept { _handlers.push_back(handler); }

		void record(const CommandHandler& handler) noexcept;

		bool containsHandlerFor(const std::string& command) const noexcept;

		void clear() noexcept { _handlers.clear(); }

		std::size_t count() const noexcept { return _handlers.size(); }

		const CommandHandler& operator[] (std::size_t index) const noexcept { return _handlers[index]; }

	private:

		std::vector<CommandHandler> _handlers;
	};

}