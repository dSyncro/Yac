#pragma once

#include <string>

#include "Commands/CommandTable.h"

namespace Yac {

	class Repl final {

	public:
		
		Repl();
		Repl(const CommandTable& commands, const VariableTable& variables);

		void run();
		void stop();

	private:

		void loop();
		void executeCommand(const Command& command) noexcept;

		bool _isRunning = false;

		CommandTable _commands;
		VariableTable _variables;
	};

}