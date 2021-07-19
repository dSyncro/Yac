#pragma once

#include <Yac/Syntax/Token.h>
#include <Yac/Syntax/Expressions/Expression.h>

namespace Yac {

	struct UnaryOperationExpression : Expression {

	public:

		UnaryOperationExpression(Operator op, Expression* operand)
			: Expression(ExpressionType::UnaryOperation), _op(op), _operand(operand)
		{
		}

		~UnaryOperationExpression() { delete _operand; }

		Operator getOperator() const noexcept { return _op; }
		const Expression* getOperand() const noexcept { return _operand; }

	private:

		Operator _op;
		Expression* _operand;
	};

}