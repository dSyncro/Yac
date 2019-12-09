#include "SyntaxTree.h"

#include <yac/Syntax/Parser/Parser.h>

using namespace Yac::Syntax;

SyntaxTree::SyntaxTree(std::string& source)
{
	Parser parser = Parser(source);
	_root = parser.Parse();
}

SyntaxTree::~SyntaxTree()
{
	Statement::Dispose(_root);
}