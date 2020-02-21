#pragma once

#include <string>

#include "Commands/CommandTable.h"

namespace Yac::Core {

	class Repl final {

	public:
		
		Repl();
		Repl(CommandTable commands, VariableTable variables);

		void Run();
		void Stop();

	private:

		void Loop();
		void ExecuteCommand(const Command& command) noexcept;

		bool _isRunning = false;

		CommandTable _commands;
		VariableTable _variables;
	};

}