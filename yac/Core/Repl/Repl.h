#pragma once

#include <string>

#include "Commands/CommandTable.h"
#include "Commands/ReplCommands.h"
#include "VariableTable.h"

namespace Yac {
	namespace Core {

		class Repl {

		public:

			void Run();
			void Stop();

		private:

			void Loop();
			void ExecuteCommand(const Command& command) noexcept;

			bool _isRunning = false;

			CommandTable _commands = ReplCommandTable;
			VariableTable _variables = VariableTable();
		};

	}
}