#include "ReplCommands.h"

using namespace Yac::Core;

void Yac::Core::ClearCallback(ParamList parameters)
{
	if (parameters.size() != 0)
	{
		Console::WriteLine("usage: #clear");
		return;
	}

	Console::Clear();
}