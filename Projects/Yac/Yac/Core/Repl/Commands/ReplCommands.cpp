#include "ReplCommands.h"

using namespace Yac;

void Yac::clearCallback(const ParameterList& parameters, VariableTable& variables)
{
	if (parameters.size() != 0)
	{
		Console::writeLine("usage: #clear");
		return;
	}

	Console::clear();
}

void Yac::debugInfoCallback(const ParameterList& parameters, VariableTable& variables)
{
	if (parameters.size() != 0)
	{
		Console::writeLine("usage: #debuginfo");
		return;
	}

	bool value = !variables.get<bool>("showdebuginfo");
	variables.set<bool>("showdebuginfo", value);
	Console::alert("show debug information: ", std::to_string(value));
}

void Yac::exitCallback(const ParameterList& parameters, VariableTable& variables)
{
	if (parameters.size() != 0)
	{
		Console::writeLine("usage: #exit");
		return;
	}

	exit(0);
}

void Yac::helpCallback(const ParameterList& parameters, VariableTable& variables)
{
	Console::newLine();
	Console::writeLine("Commands: ");
	for (std::size_t i = 0; i < replCommandTable.count(); i++)
	{
		Console::writeLine(replCommandTable[i].getCommandName());
	}
	Console::newLine();
}