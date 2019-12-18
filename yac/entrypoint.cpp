#include <iostream>

#include <yac/Syntax/SyntaxRules.h>
#include <yac/Syntax/SyntaxTree/SyntaxTree.h>
#include <yac\DataTypes\UInt.h>
#include <yac\DataTypes\Float.h>
#include <yac\DataTypes\Double.h>
#include <yac\Syntax\Expressions\Operations\BinaryOperation.h>
#include <yac\Syntax\Expressions\Numeric\NumericLiteral.h>
#include <yac/Syntax/Statements/Statements.h>

using namespace Yac::Syntax;

int main(int argc, char** argv)
{
	while (true)
	{
		std::string line;
		std::getline(std::cin, line);

		//for (int i = 0; i < 1000; i++)
			SyntaxTree tree = SyntaxTree(line);
	}
}