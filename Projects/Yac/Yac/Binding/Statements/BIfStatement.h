#pragma once

#include <Yac/Binding/Scopes/BlockScope.h>
#include <Yac/Binding/Statements/BStatement.h>
#include <Yac/Binding/Expressions/BExpression.h>

namespace Yac {

	struct BIfStatement final : BStatement {

		BIfStatement(BExpression* bCondition, BStatement* bStatement, BStatement* bElseStatement, BlockScope* scope) 
			: BStatement(StatementType::If, scope),
			condition(bCondition), ifStatement(bStatement), elseStatement(bElseStatement) { }

		BExpression* condition;
		BStatement* ifStatement;
		BStatement* elseStatement;

		bool isElseStatementPresent() const noexcept { return elseStatement != nullptr; }
	};

}