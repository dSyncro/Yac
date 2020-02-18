#include "CommandHandler.h"

using namespace Yac::Core;

CommandHandler::CommandHandler(std::string command, CommandCallback callback) : _cmd(command), _callback(callback) {}

bool CommandHandler::Cast(const Command& command, VariableTable& variables) const noexcept
{
	if (command.Name() != _cmd) return false;

	_callback(command.Parameters(), variables);
	return true;
}