#include "SyntaxTree.h"

#include <iostream>

#include <yac/Syntax/Parser/Parser.h>
#include <yac/Errors/ErrorList.h>

using namespace Yac::Syntax;
using namespace Yac::Errors;

SyntaxTree::SyntaxTree(std::string& source)
{
	Parser parser = Parser(source);
	_root = parser.Parse();
	ErrorList& e = parser.errors();
	if (parser.errors().Any())
	{
		for (unsigned int i = 0; i < e.Count(); i++)
			std::cout << e[i].message() << std::endl;
	}
	e.Clear();
}

SyntaxTree::~SyntaxTree()
{
	Statement::Dispose(_root);
}