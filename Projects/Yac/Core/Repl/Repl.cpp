#include "Repl.h"

#include <API/Bool.h>

#include <Errors/ErrorList.h>
#include <Libraries/Console/Console.h>
#include <Syntax/Executor/Executor.h>
#include <Syntax/SyntaxTree/CompilationUnit.h>
#include <Syntax/SyntaxTree/AstPrinter.h>

#include "Commands/ReplCommands.h"
#include "VariableTable.h"

using namespace Yac::Api;
using namespace Yac::Core;
using namespace Yac::Errors;
using namespace Yac::Syntax;

Repl::Repl() : _commands(ReplCommandTable), _variables(VariableTable()) {}
Repl::Repl(CommandTable commands, VariableTable variables) : _commands(commands), _variables(variables) {}

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

		CompilationUnit unit = CompilationUnit(line);

		const ErrorList& e = unit.errors();
		if (e.Any())
		{
			for (unsigned int i = 0; i < e.Count(); i++)
				Console::Error(e[i].message());
		}
		else
		{
			Bool showsDebug = _variables.Get<Bool>("showdebuginfo");
			if (showsDebug)
				AstPrinter::Print(unit.Tree);
		}

		//Executor e = Executor(tree);
		//Console::Alert(e.Execute());
	}
}

void Repl::ExecuteCommand(const Command& command) noexcept
{
	_commands.InvokeAll(command, _variables);
}