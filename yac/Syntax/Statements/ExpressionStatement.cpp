#include "ExpressionStatement.h"

using namespace Yac::Syntax;

ExpressionStatement::ExpressionStatement(Expression* expression) : 
	Statement(StatementType::Expression), _expr(expression) {}