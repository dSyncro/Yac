#include "ReplCommands.h"

#include <API/Bool.h>

using namespace Yac::Core;
using namespace Yac::Api;

void Yac::Core::ClearCallback(ParamList parameters, VariableTable& variables)
{
	if (parameters.size() != 0)
	{
		Console::WriteLine("usage: #clear");
		return;
	}

	Console::Clear();
}

void Yac::Core::DebugInfoCallback(ParamList parameters, VariableTable& variables)
{
	if (parameters.size() != 0)
	{
		Console::WriteLine("usage: #debuginfo");
		return;
	}

	Bool value = !variables.Get<Bool>("showdebuginfo");
	variables.Set<Bool>("showdebuginfo", value);
	Console::Alert("show debug information: ", value.ToString());
}

void Yac::Core::ExitCallback(ParamList parameters, VariableTable& variables)
{
	if (parameters.size() != 0)
	{
		Console::WriteLine("usage: #exit");
		return;
	}

	exit(0);
}