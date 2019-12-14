#pragma once

#include <string>

#include "Expression.h"

namespace Yac {
	namespace Syntax {

		struct AssignmentExpression : Expression {

		public:

			AssignmentExpression(std::string id, Expression* expression)
				: Expression(ExpressionType::AssignmentExpression), _id(id), _expr(expression) {}

			~AssignmentExpression() { delete _expr; }

			inline std::string identifier() const noexcept { return _id; }
			inline Expression* expression() const noexcept { return _expr; }

		private:

			std::string _id;
			Expression* _expr;
		};

	}
}