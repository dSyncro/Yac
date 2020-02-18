#include "CommandTable.h"

using namespace Yac::Core;

CommandTable::CommandTable(std::vector<CommandHandler> handlers) : _handlers(handlers) {}

void CommandTable::Invoke(const Command& command, VariableTable& variables) const noexcept
{
	for (const CommandHandler& handler : _handlers)
		if (handler.Cast(command, variables)) return;
}

void CommandTable::InvokeAll(const Command& command, VariableTable& variables) const noexcept
{
	for (const CommandHandler& handler : _handlers)
		handler.Cast(command, variables);
}

void CommandTable::Register(const CommandHandler& handler) noexcept
{
	if (!ContainsHandlerFor(handler.CommandName())) Add(handler);
}

bool CommandTable::ContainsHandlerFor(const std::string& command) const noexcept
{
	for (const CommandHandler& h : _handlers)
		if (h.CommandName() == command) return true;
	return false;
}