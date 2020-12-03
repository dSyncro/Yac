#pragma once

#include "CommandTable.h"

#include <Libraries/Console/Console.h>

namespace Yac::Core {

	void clearCallback(const ParameterList& parameters, VariableTable& variables);
	void debugInfoCallback(const ParameterList& parameters, VariableTable& variables);
	void exitCallback(const ParameterList& parameters, VariableTable& variables);

	const CommandHandler clearHandler = CommandHandler("clear", clearCallback);
	const CommandHandler debugInfoHandler = CommandHandler("debuginfo", debugInfoCallback);
	const CommandHandler exitHandler = CommandHandler("exit", exitCallback);

	const CommandTable ReplCommandTable({ clearHandler, debugInfoHandler, exitHandler });

}