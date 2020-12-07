#include "ReplCommands.h"

#include <Yac/API/Bool.h>

using namespace Yac::Core;
using namespace Yac::Api;

void Yac::Core::clearCallback(const ParameterList& parameters, VariableTable& variables)
{
	if (parameters.size() != 0)
	{
		Console::writeLine("usage: #clear");
		return;
	}

	Console::clear();
}

void Yac::Core::debugInfoCallback(const ParameterList& parameters, VariableTable& variables)
{
	if (parameters.size() != 0)
	{
		Console::writeLine("usage: #debuginfo");
		return;
	}

	Bool value = !variables.get<Bool>("showdebuginfo");
	variables.set<Bool>("showdebuginfo", value);
	Console::alert("show debug information: ", value.toString());
}

void Yac::Core::exitCallback(const ParameterList& parameters, VariableTable& variables)
{
	if (parameters.size() != 0)
	{
		Console::writeLine("usage: #exit");
		return;
	}

	exit(0);
}