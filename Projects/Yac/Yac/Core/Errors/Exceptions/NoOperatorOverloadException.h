#pragma once

#include <Yac/Core/Types/TypeSymbol.h>
#include <Yac/Syntax/Operator.h>

namespace Yac::Errors {

	struct NoUnaryOperatorOverloadException : std::exception {

	public:

		NoUnaryOperatorOverloadException(const Core::TypeSymbol& operandType, Syntax::Operator op)
		{
			_msg = "No unary operator for operation `" + Syntax::toString(op)  
				+ "` with operand of type <" + operandType.getName() + '>';
		}

		const char* what() const noexcept override { return _msg.c_str(); }

	private:

		std::string _msg;

	};

	struct NoBinaryOperatorOverloadException : std::exception {

	public:

		NoBinaryOperatorOverloadException(const Core::TypeSymbol& leftOperandType, const Core::TypeSymbol& rightOperandType, Syntax::Operator op)
		{
			_msg = "No binary operator for operation `" + Syntax::toString(op)
				+ "` with left operand of type <" + leftOperandType.getName() + '>'
				+ " and right operand of type <" + rightOperandType.getName() + '>';
		}

		const char* what() const noexcept override { return _msg.c_str(); }

	private:

		std::string _msg;

	};

}