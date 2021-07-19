#pragma once

#include <Yac/Binding/Expressions/BExpression.h>
#include <Yac/Core/Namespace.h>

namespace Yac {

	struct BAssignmentExpression final : BExpression {

		BAssignmentExpression(const std::string& lvalue, AssignmentOperator assignmentOp, BExpression* rvalue, const Namespace& scope) 
			: BExpression(ExpressionType::Assignment, scope.findTypeOfName(lvalue)), name(lvalue), op(assignmentOp), expression(rvalue) { }

		std::string name;
		AssignmentOperator op;
		BExpression* expression;

	};
}