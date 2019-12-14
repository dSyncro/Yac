#include <iostream>

#include <yac/Syntax/SyntaxRules.h>
#include <yac/Syntax/SyntaxTree/SyntaxTree.h>
#include <yac\Syntax\Statements\VariableDeclaration.h>
#include <yac\DataTypes\UInt.h>
#include <yac\DataTypes\Float.h>
#include <yac\DataTypes\Double.h>
#include <yac\Syntax\Expressions\Operations\BinaryOperation.h>
#include <yac\Syntax\Expressions\Numeric\NumericLiteral.h>

using namespace Yac::Syntax;

int main(int argc, char** argv)
{
	while (true)
	{
		std::string line;
		std::getline(std::cin, line);

		SyntaxTree tree = SyntaxTree(line);
		VariableDeclaration& v = *(VariableDeclaration*)tree.root();
		BinaryOperation& b = *(BinaryOperation*)v.initializer();
		NumericLiteral& left = *(NumericLiteral*)b.left();
		NumericLiteral& right = *(NumericLiteral*)b.right();
	}
}