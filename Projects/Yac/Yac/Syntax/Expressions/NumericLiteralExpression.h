#pragma once

#include <Yac/Core/NumericBase.h>
#include <Yac/Core/NumericType.h>
#include <Yac/Syntax/Token.h>
#include <Yac/Syntax/Expressions/Expression.h>
#include <Yac/Core/Numeric.h>

namespace Yac {

	struct NumericLiteralExpression final : Expression {

	public:

		NumericLiteralExpression(const std::string& text, NumericType type, NumericBase base = NumericBase::Decimal)
			: Expression(ExpressionType::NumericLiteral), _numericType(type), _number(Numeric::parse(text, type, base)) { }

		Numeric getNumeric() const noexcept { return _number; }
		NumericType getNumericType() const noexcept { return _numericType; }

	private:

		NumericType _numericType;
		Numeric _number;
	};

}