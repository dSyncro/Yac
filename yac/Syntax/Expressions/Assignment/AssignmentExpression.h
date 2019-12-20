#pragma once

#include "AssignmentOperator.h"

#include <string>

#include <yac/Syntax/Expressions/Expression.h>

namespace Yac {
	namespace Syntax {

		struct AssignmentExpression : Expression {

		public:

			AssignmentExpression(std::string id, AssignmentOperator op,  Expression* expression)
				: Expression(ExpressionType::AssignmentExpression), _id(id), _op(op), _expr(expression) {}

			~AssignmentExpression() { delete _expr; }

			inline std::string identifier() const noexcept { return _id; }
			inline AssignmentOperator assignmentOperator() const noexcept { return _op; }
			inline const Expression* expression() const noexcept { return _expr; }

		private:

			std::string _id;
			AssignmentOperator _op;
			Expression* _expr;
		};

	}
}