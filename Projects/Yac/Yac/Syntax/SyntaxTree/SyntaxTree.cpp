#include "SyntaxTree.h"
#include "AstPrinter.h"

#include <iostream>

#include <Console.h>

#include <Yac/Syntax/Parser.h>
#include <Yac/Syntax/Statements.h>

using namespace Yac;
using namespace Yac::Core;
using namespace Yac::Errors;

SyntaxTree::SyntaxTree(const SourceText& source, ErrorList& errorList)
{
	Parser parser = Parser(source, errorList);
	_root = std::shared_ptr<Statement>(parser.Parse());
}