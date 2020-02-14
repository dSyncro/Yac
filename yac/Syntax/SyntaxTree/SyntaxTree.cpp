#include "SyntaxTree.h"
#include "AstPrinter.h"

#include <iostream>

#include <yac/Syntax/Parser/Parser.h>
#include <yac/Errors/ErrorList.h>
#include <yac/Syntax/Statements/Statements.h>
#include <yac/Libraries/Console/Console.h>

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
			Console::Error(e[i].message());
	}
	else AstPrinter::Print(this);
	e.Clear();
}

SyntaxTree::~SyntaxTree()
{
	delete _root;
}