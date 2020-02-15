#include "Executor.h"

#include <yac/Syntax/Statements/Statements.h>

using namespace Yac::Syntax;

Executor::Executor(const SyntaxTree& tree)  : _root(tree.root()) {}

int Executor::Execute()
{
	switch (_root->type())
	{
		case StatementType::Expression: return EvaluateExpressionStatement();
		default: return 0;
	}
}

int Executor::EvaluateExpressionStatement()
{
	const ExpressionStatement* statement = (ExpressionStatement*)_root;
	switch (statement->expression()->type())
	{
		case ExpressionType::NumericLiteral: return ((NumericLiteral*)statement->expression())->ToInt();
		case ExpressionType::BooleanLiteral: return ((BooleanLiteral*)statement->expression())->value();
		default: return 0;
	}
}