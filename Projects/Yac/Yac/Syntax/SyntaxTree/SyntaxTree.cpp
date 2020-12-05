#include "SyntaxTree.h"
#include "AstPrinter.h"

#include <iostream>

#include <Yac/Syntax/Parser.h>
#include <Yac/Syntax/Statements/Statements.h>
#include <Yac/Libraries/Console/Console.h>

using namespace Yac::Text;
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