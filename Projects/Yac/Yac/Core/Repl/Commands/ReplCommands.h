#pragma once

#include "CommandTable.h"

#include <Console.h>

namespace Yac {

	// TODO: Automate with macros?

	void clearCallback(const ParameterList& parameters, VariableTable& variables);
	void debugInfoCallback(const ParameterList& parameters, VariableTable& variables);
	void exitCallback(const ParameterList& parameters, VariableTable& variables);
	void helpCallback(const ParameterList& parameters, VariableTable& variables);

	const CommandHandler clearHandler = CommandHandler("clear", clearCallback);
	const CommandHandler debugInfoHandler = CommandHandler("debuginfo", debugInfoCallback);
	const CommandHandler exitHandler = CommandHandler("exit", exitCallback);
	const CommandHandler helpHandler = CommandHandler("help", helpCallback);

	const CommandTable replCommandTable({ clearHandler, debugInfoHandler, exitHandler, helpHandler });

}