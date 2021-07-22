#pragma once

#include <Yac/Binding/Scopes/Scope.h>
#include <Yac/Binding/Expressions/BExpression.h>
#include <Yac/Binding/Statements/BStatement.h>

namespace Yac {

	struct BExpressionStatement final : BStatement {

		BExpressionStatement(BExpression* boundExpression, Scope* scope)
			: BStatement(StatementType::Expression, scope), expression(boundExpression) { }

		BExpression* expression;

	};

}