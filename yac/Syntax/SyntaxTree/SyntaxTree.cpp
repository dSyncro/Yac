#include "SyntaxTree.h"
#include "AstPrinter.h"

#include <iostream>

#include <yac/Syntax/Parser/Parser.h>
#include <yac/Syntax/Statements/Statements.h>
#include <yac/Libraries/Console/Console.h>

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