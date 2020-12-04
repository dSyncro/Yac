#include "CommandHandler.h"

using namespace Yac::Core;

CommandHandler::CommandHandler(std::string command, CommandCallback callback) : _cmd(command), _callback(callback) {}

bool CommandHandler::cast(const Command& command, VariableTable& variables) const noexcept
{
	if (command.getName() != _cmd) return false;

	_callback(command.getParameters(), variables);
	return true;
}