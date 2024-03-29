#include "Repl.h"

#include <Console.h>

#include <Yac/Core/Errors/ErrorList.h>
#include <Yac/Syntax/SyntaxTree/CompilationUnit.h>
#include <Yac/Syntax/SyntaxTree/AstPrinter.h>

#include "Commands/ReplCommands.h"
#include "VariableTable.h"
#include <Yac/Binding/Binder.h>

using namespace Yac;
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
		Console::writeColored(AnsiStyle::Forecolors::Magenta, ">> ");

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
				Console::error(e[i].getMessage());
		}
		else
		{
			bool showsDebug = _variables.get<bool>("showdebuginfo");
			if (showsDebug)
				AstPrinter::print(unit.syntaxTree);
		}

		Binder b;
		BSyntaxTree bound = b.bind(unit.syntaxTree);
	}
}

void Repl::executeCommand(const Command& command) noexcept
{
	if (!_commands.containsHandlerFor(command.getName()))
		Console::error("Command '#", command.getName(), "' not found. Type '#help' for a list of available commands");
	_commands.invokeAll(command, _variables);
}