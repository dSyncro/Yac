#pragma once

#include "Operator.h"

#include <Yac/Syntax/Token.h>
#include <Yac/Syntax/Expressions/Expression.h>

namespace Yac::Syntax {

	struct BinaryOperationExpression : Expression {

	public:

		BinaryOperationExpression(Expression* left, Operator operation, Expression* right)
			: Expression(ExpressionType::BinaryOperation), _left(left), _operation(operation), _right(right)
		{
		}

		~BinaryOperationExpression()
		{
			delete _left;
			delete _right;
		}

		const Expression* getLeft() const noexcept { return _left; }
		Operator getOperation() const noexcept { return _operation; }
		const Expression* getRight() const noexcept { return _right; }

	private:

		Expression* _left;
		Operator _operation;
		Expression* _right;
	};

}