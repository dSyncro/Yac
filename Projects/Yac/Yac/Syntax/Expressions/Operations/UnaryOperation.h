#pragma once

#include "Operator.h"

#include <Yac/Syntax/Tokens/Token.h>
#include <Yac/Syntax/Expressions/Expression.h>

namespace Yac::Syntax {

	struct UnaryOperation : Expression {

	public:

		UnaryOperation(Operator operation, Expression* operand);
		~UnaryOperation();

		Operator getOperation() const noexcept { return _operation; }
		const Expression* getOperand() const noexcept { return _operand; }

	private:

		Operator _operation;
		Expression* _operand;
	};

}