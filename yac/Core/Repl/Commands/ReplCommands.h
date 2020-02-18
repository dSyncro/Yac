#pragma once

#include "CommandTable.h"

#include <yac/Libraries/Console/Console.h>

namespace Yac {
	namespace Core {

		extern void ClearCallback(ParamList parameters, VariableTable& variables);
		extern void DebugInfoCallback(ParamList parameters, VariableTable& variables);

		const CommandHandler clearHandler = CommandHandler("clear", ClearCallback);
		const CommandHandler debugInfoHandler = CommandHandler("debuginfo", DebugInfoCallback);

		const CommandTable ReplCommandTable({ clearHandler, debugInfoHandler });

	}
}