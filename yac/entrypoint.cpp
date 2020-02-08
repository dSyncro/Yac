#include <iostream>

#include <yac/Syntax/SyntaxRules.h>
#include <yac/Syntax/SyntaxTree/SyntaxTree.h>
#include <yac\Syntax\Expressions\Operations\BinaryOperation.h>
#include <yac\Syntax\Expressions\Numeric\NumericLiteral.h>
#include <yac/Syntax/Statements/Statements.h>
#include <yac\Text\SourceText.h>

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