#pragma once

#include "CommandTable.h"

#include <yac/Libraries/Console/Console.h>

namespace Yac {
	namespace Core {

		extern void ClearCallback(ParamList parameters);

		const CommandHandler clearHandler = CommandHandler("clear", ClearCallback);

		const CommandTable ReplCommandTable({ clearHandler });

	}
}