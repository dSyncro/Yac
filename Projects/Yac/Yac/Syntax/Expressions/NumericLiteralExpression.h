#pragma once

#include <Yac/Core/NumericBase.h>
#include <Yac/Core/NumericType.h>
#include <Yac/Syntax/Token.h>
#include <Yac/Syntax/Expressions/Expression.h>

namespace Yac::Syntax {

	struct NumericLiteralExpression final : Expression {

	public:

		NumericLiteralExpression(const std::string& text, Core::NumericType type, Core::NumericBase base = Core::NumericBase::Decimal)
			: Expression(ExpressionType::NumericLiteral), _text(text), _base(base), _numericType(type) { }

		Core::NumericType getNumericType() const noexcept { return _numericType; }
		Core::NumericBase getBase() const noexcept { return _base; }
		const std::string& getText() const noexcept { return _text; }

		IntT toInt() const { return std::stoi(_text, nullptr, static_cast<UIntT>(_base)); }
		UIntT toUInt() const { return std::stoul(_text, nullptr, static_cast<UIntT>(_base)); }
		float toFloat() const { return std::stof(_text); }
		double toDouble() const { return std::stod(_text); }

	private:

		Core::NumericType _numericType;
		Core::NumericBase _base;
		std::string _text;
	};

}