#include "SyntaxTree.h"
#include "AstPrinter.h"

#include <iostream>

#include <Syntax/Parser/Parser.h>
#include <Syntax/Statements/Statements.h>
#include <Libraries/Console/Console.h>

using namespace Yac::Text;
using namespace Yac::Syntax;
using namespace Yac::Errors;

SyntaxTree::SyntaxTree(SourceText source, ErrorList& errorList)
{
	Parser parser = Parser(source, errorList);
	_root = parser.Parse();
}

SyntaxTree::~SyntaxTree()
{
	delete _root;
}