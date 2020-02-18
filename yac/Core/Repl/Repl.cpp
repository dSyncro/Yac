#include "Repl.h"

#include <yac/API/Bool.h>

#include <yac/Libraries/Console/Console.h>
#include <yac/Syntax/Executor/Executor.h>
#include <yac/Syntax/SyntaxTree/SyntaxTree.h>
#include <yac/Syntax/SyntaxTree/AstPrinter.h>

using namespace Yac::Api;
using namespace Yac::Core;
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
			Command command = Command::Parse(line);
			ExecuteCommand(command);
			continue;
		}

		SyntaxTree tree = SyntaxTree(line);
		Bool showsDebug = _variables.Get<Bool>("showdebuginfo");
		if (showsDebug) 
			AstPrinter::Print(tree);

		//Executor e = Executor(tree);
		//Console::Alert(e.Execute());
	}
}

void Repl::ExecuteCommand(const Command& command) noexcept
{
	_commands.InvokeAll(command, _variables);
}