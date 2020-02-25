#pragma once

#include <Syntax/Tokens/Token.h>
#include <Syntax/Expressions/Expression.h>
#include <Syntax/Expressions/Numeric/NumericBase.h>
#include <Syntax/Expressions/Numeric/NumericType.h>

namespace Yac::Syntax {

	struct NumericLiteral final : Expression {

	public:

		NumericLiteral(std::string text, NumericType type, NumericBase base = NumericBase::Decimal);

		inline NumericType numeric_type() const noexcept { return _numericType; }
		inline NumericBase base() const noexcept { return _base; }
		inline std::string text() const noexcept { return _text; }

		inline int ToInt() const { return std::stoi(_text, nullptr, (unsigned int)_base); }
		inline unsigned int ToUInt() const { return std::stoul(_text, nullptr, (unsigned int)_base); }
		inline float ToFloat() const { return std::stof(_text); }
		inline double ToDouble() const { return std::stod(_text); }

	private:

		NumericType _numericType;
		NumericBase _base;
		std::string _text;
	};

}