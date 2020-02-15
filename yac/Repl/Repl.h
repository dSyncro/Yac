#pragma once

#include <string>

namespace Yac {

	class Repl {

	public:

		void Run();
		void Stop();

	private:

		void Loop();
		void ExecuteCommand(const std::string& command);

		bool _isRunning = false;
	};

}