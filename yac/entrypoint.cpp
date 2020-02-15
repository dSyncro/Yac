#include <iostream>

#include <yac/Syntax/SyntaxTree/SyntaxTree.h>
#include <yac/Libraries/Console/Console.h>
#include <yac/Syntax/Executor/Executor.h>

using namespace Yac::Syntax;

int main(int argc, char** argv)
{
	while (true)
	{
		std::string line;
		Console::WriteColored(AnsiStyle::Forecolors::Magenta, ">> ");
		std::getline(std::cin, line);
		SyntaxTree tree = SyntaxTree(line);
		Executor e = Executor(tree);
		Console::Alert(e.Execute());
	}
}