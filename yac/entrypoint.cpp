#include <iostream>

#include <yac/Syntax/SyntaxTree/SyntaxTree.h>

using namespace Yac::Syntax;

int main(int argc, char** argv)
{
	while (true)
	{
		std::string line;
		std::getline(std::cin, line);
		SyntaxTree tree = SyntaxTree(line);
	}
}