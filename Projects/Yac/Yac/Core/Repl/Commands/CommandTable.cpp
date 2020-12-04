#include "CommandTable.h"

using namespace Yac::Core;

CommandTable::CommandTable(std::vector<CommandHandler> handlers) : _handlers(handlers) {}

void CommandTable::invoke(const Command& command, VariableTable& variables) const noexcept
{
	for (const CommandHandler& handler : _handlers)
		if (handler.cast(command, variables)) return;
}

void CommandTable::invokeAll(const Command& command, VariableTable& variables) const noexcept
{
	for (const CommandHandler& handler : _handlers)
		handler.cast(command, variables);
}

void CommandTable::record(const CommandHandler& handler) noexcept
{
	if (!containsHandlerFor(handler.getCommandName())) 
		push(handler);
}

bool CommandTable::containsHandlerFor(const std::string& command) const noexcept
{
	for (const CommandHandler& h : _handlers)
		if (h.getCommandName() == command) return true;
	return false;
}