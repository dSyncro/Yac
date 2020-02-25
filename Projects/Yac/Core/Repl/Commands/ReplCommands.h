#pragma once

#include "CommandTable.h"

#include <Libraries/Console/Console.h>

namespace Yac::Core {

	void ClearCallback(ParamList parameters, VariableTable& variables);
	void DebugInfoCallback(ParamList parameters, VariableTable& variables);
	void ExitCallback(ParamList parameters, VariableTable& variables);

	const CommandHandler clearHandler = CommandHandler("clear", ClearCallback);
	const CommandHandler debugInfoHandler = CommandHandler("debuginfo", DebugInfoCallback);
	const CommandHandler exitHandler = CommandHandler("exit", ExitCallback);

	const CommandTable ReplCommandTable({ clearHandler, debugInfoHandler, exitHandler });

}