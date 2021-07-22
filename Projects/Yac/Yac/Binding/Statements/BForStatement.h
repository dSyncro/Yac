#pragma once

#include <Yac/Binding/Scopes/BlockScope.h>
#include <Yac/Binding/Statements/BStatement.h>
#include <Yac/Binding/Expressions/BExpression.h>

namespace Yac {

	struct BForStatement final : BStatement {

		BForStatement(BExpression* bAssignment, BExpression* bCondition, BExpression* bUpdate, BStatement* bStatement, BlockScope* scope) 
			: BStatement(StatementType::For, scope), 
			assignment(bAssignment), condition(bCondition), update(bUpdate), statement(bStatement) { }

		BExpression* assignment;
		BExpression* condition;
		BExpression* update;
		BStatement* statement;

	};

}