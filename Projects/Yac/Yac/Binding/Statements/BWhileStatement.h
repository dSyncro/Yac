#pragma once

#include <Yac/Binding/Scopes/BlockScope.h>
#include <Yac/Binding/Statements/BStatement.h>
#include <Yac/Binding/Expressions/BExpression.h>

namespace Yac {

	struct BWhileStatement final : BStatement {

		BWhileStatement(BExpression* bCondition, BStatement* bStatement, BlockScope* scope) 
			: BStatement(StatementType::While, scope),
			condition(bCondition), statement(bStatement) { }

		BExpression* condition;
		BStatement* statement;
	};

}