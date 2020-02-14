#include <iostream>

#include <yac/Syntax/SyntaxTree/SyntaxTree.h>
#include <yac/Libraries/Console/Console.h>

using namespace Yac::Syntax;

int main(int argc, char** argv)
{
	while (true)
	{
		std::string line;
		Console::WriteColored(AnsiStyle::Forecolors::Magenta, ">> ");
		std::getline(std::cin, line);
		SyntaxTree tree = SyntaxTree(line);
	}
}