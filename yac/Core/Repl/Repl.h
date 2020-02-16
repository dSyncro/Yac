#pragma once

#include <string>

#include "Commands/CommandTable.h"
#include "Commands/ReplCommands.h"

namespace Yac {
	namespace Core {

		class Repl {

		public:

			void Run();
			void Stop();

		private:

			void Loop() const;
			void ExecuteCommand(const Command& command) const noexcept;

			bool _isRunning = false;

			CommandTable _commands = ReplCommandTable;
		};

	}
}