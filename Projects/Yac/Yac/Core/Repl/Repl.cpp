#include "Repl.h"

#include <Yac/API/Bool.h>

#include <Yac/Errors/ErrorList.h>
#include <Yac/Libraries/Console/Console.h>
#include <Yac/Syntax/Executor/Executor.h>
#include <Yac/Syntax/SyntaxTree/CompilationUnit.h>
#include <Yac/Syntax/SyntaxTree/AstPrinter.h>

#include "Commands/ReplCommands.h"
#include "VariableTable.h"

using namespace Yac::Api;
using namespace Yac::Core;
using namespace Yac::Errors;
using namespace Yac::Syntax;

Repl::Repl() : _commands(replCommandTable), _variables(VariableTable()) {}
Repl::Repl(const CommandTable& commands, const VariableTable& variables) : _commands(commands), _variables(variables) {}

void Repl::run()
{
	// If already running return
	if (_isRunning) return;

	// Start Run-Evaluate-Print-Loop
	_isRunning = true;
	loop();
}

void Repl::stop()
{
	_isRunning = false;
}

void Repl::loop()
{
	while (_isRunning)
	{
		Console::WriteColored(AnsiStyle::Forecolors::Magenta, ">> ");

		std::string line;
		std::getline(std::cin, line);

		if (line.empty()) continue;

		// TODO: consider trimming whitespaces

		if (line[0] == '#')
		{
			Command command = Command::parse(line);
			executeCommand(command);
			continue;
		}

		CompilationUnit unit = CompilationUnit(line);

		const ErrorList& e = unit.getErrors();
		if (e.any())
		{
			for (UIntT i = 0; i < e.count(); i++)
				Console::Error(e[i].getMessage());
		}
		else
		{
			Bool showsDebug = _variables.get<Bool>("showdebuginfo");
			if (showsDebug)
				AstPrinter::print(unit.syntaxTree);
		}

		//Executor e = Executor(tree);
		//Console::Alert(e.Execute());
	}
}

void Repl::executeCommand(const Command& command) noexcept
{
	if (!_commands.containsHandlerFor(command.getName()))
		Console::Error("Command '#", command.getName(), "' not found. Type '#help' for a list of available commands");
	_commands.invokeAll(command, _variables);
}