#pragma once

#include <Yac/Syntax/Token.h>
#include <Yac/Syntax/Expressions/Expression.h>

namespace Yac {

	struct UnaryOperationExpression : Expression {

	public:

		UnaryOperationExpression(Operator operation, Expression* operand)
			: Expression(ExpressionType::UnaryOperation), _operation(operation), _operand(operand)
		{
		}

		~UnaryOperationExpression() { delete _operand; }

		Operator getOperation() const noexcept { return _operation; }
		const Expression* getOperand() const noexcept { return _operand; }

	private:

		Operator _operation;
		Expression* _operand;
	};

}