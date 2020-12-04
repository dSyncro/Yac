#pragma once

#include <Yac/Syntax/Tokens/Token.h>
#include <Yac/Syntax/Expressions/Expression.h>
#include <Yac/Syntax/Expressions/Numeric/NumericBase.h>
#include <Yac/Syntax/Expressions/Numeric/NumericType.h>

namespace Yac::Syntax {

	struct NumericLiteral final : Expression {

	public:

		NumericLiteral(const std::string& text, NumericType type, NumericBase base = NumericBase::Decimal);

		NumericType getNumericType() const noexcept { return _numericType; }
		NumericBase getBase() const noexcept { return _base; }
		const std::string& getText() const noexcept { return _text; }

		IntT toInt() const { return std::stoi(_text, nullptr, static_cast<UIntT>(_base)); }
		UIntT toUInt() const { return std::stoul(_text, nullptr, static_cast<UIntT>(_base)); }
		float toFloat() const { return std::stof(_text); }
		double toDouble() const { return std::stod(_text); }

	private:

		NumericType _numericType;
		NumericBase _base;
		std::string _text;
	};

}