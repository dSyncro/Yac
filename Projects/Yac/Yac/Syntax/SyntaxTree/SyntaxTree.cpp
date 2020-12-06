#include "SyntaxTree.h"
#include "AstPrinter.h"

#include <iostream>

#include <Libraries/Console/Console.h>

#include <Yac/Syntax/Parser.h>
#include <Yac/Syntax/Statements.h>

using namespace Yac::Core;
using namespace Yac::Syntax;
using namespace Yac::Errors;

SyntaxTree::SyntaxTree(const SourceText& source, ErrorList& errorList)
{
	Parser parser = Parser(source, errorList);
	_root = parser.Parse();
}

SyntaxTree::~SyntaxTree()
{
	delete _root;
}