#include "Repl.h"

#include <yac/Libraries/Console/Console.h>
#include <yac/Syntax/Executor/Executor.h>
#include <yac/Syntax/SyntaxTree/SyntaxTree.h>

using namespace Yac;
using namespace Yac::Syntax;

void Repl::Run()
{
	if (_isRunning) return;
	_isRunning = true;
	Loop();
}

void Repl::Stop()
{
	_isRunning = false;
}

void Repl::Loop()
{
	while (_isRunning)
	{
		std::string line;
		Console::WriteColored(AnsiStyle::Forecolors::Magenta, ">> ");
		std::getline(std::cin, line);

		if (line.empty()) continue;

		if (line[0] == '#')
		{
			ExecuteCommand(line);
			continue;
		}

		SyntaxTree tree = SyntaxTree(line);
		Executor e = Executor(tree);
		Console::Alert(e.Execute());
	}
}

void Repl::ExecuteCommand(const std::string& command)
{
	if (command == "#clear") Console::Clear();
}