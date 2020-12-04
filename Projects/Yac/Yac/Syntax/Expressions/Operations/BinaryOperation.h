#pragma once

#include "Operator.h"

#include <Yac/Syntax/Tokens/Token.h>
#include <Yac/Syntax/Expressions/Expression.h>

namespace Yac::Syntax {

	struct BinaryOperation : Expression {

	public:

		BinaryOperation(Expression* left, Operator operation, Expression* right);
		~BinaryOperation();

		const Expression* getLeft() const noexcept { return _left; }
		Operator getOperation() const noexcept { return _operation; }
		const Expression* getRight() const noexcept { return _right; }

	private:

		Expression* _left;
		Operator _operation;
		Expression* _right;
	};

}