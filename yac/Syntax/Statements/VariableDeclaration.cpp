#include "VariableDeclaration.h"

using namespace Yac::Syntax;

VariableDeclaration::VariableDeclaration(Keyword keyword, std::string name, Expression* initializer) :
	Statement(StatementType::VariableDeclaration), _keyword(keyword), _name(name), _init(initializer) {}

VariableDeclaration::~VariableDeclaration() { Expression::Dispose(_init); }