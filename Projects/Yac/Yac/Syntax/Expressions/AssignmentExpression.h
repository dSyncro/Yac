#pragma once

#include <string>

#include <Yac/Syntax/Operator.h>
#include <Yac/Syntax/Expressions/Expression.h>

namespace Yac {

	struct AssignmentExpression : Expression {

	public:

		AssignmentExpression(const std::string& id, AssignmentOperator op, Expression* expression)
			: Expression(ExpressionType::Assignment), _id(id), _op(op), _expr(expression)
		{
		}

		~AssignmentExpression() { delete _expr; }

		const std::string& getIdentifier() const noexcept { return _id; }
		AssignmentOperator getAssignmentOperator() const noexcept { return _op; }
		const Expression* getExpression() const noexcept { return _expr; }

	private:

		std::string _id;
		AssignmentOperator _op;
		Expression* _expr;
	};
}