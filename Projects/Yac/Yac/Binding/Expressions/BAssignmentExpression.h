#pragma once

#include <Yac/Binding/Expressions/BExpression.h>
#include <Yac/Binding/Scopes/Scope.h>

namespace Yac {

	struct BAssignmentExpression final : BExpression {

		BAssignmentExpression(const std::string& lvalue, AssignmentOperator assignmentOp, BExpression* rvalue, Scope* scope) 
			: BExpression(ExpressionType::Assignment, scope->findTypeOfIdentifier(lvalue)), name(lvalue), op(assignmentOp), expression(rvalue) { }

		std::string name;
		AssignmentOperator op;
		BExpression* expression;

	};
}