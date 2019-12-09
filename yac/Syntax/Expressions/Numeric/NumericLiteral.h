#pragma once

#include <yac/Syntax/Tokens/Token.h>
#include <yac/Syntax/Expressions/Expression.h>
#include <yac/Syntax/Expressions/Numeric/NumericBase.h>
#include <yac/Syntax/Expressions/Numeric/NumericType.h>

namespace Yac {
	namespace Syntax {

		struct NumericLiteral : Expression {

		public:

			NumericLiteral(std::string text, NumericType type, NumericBase base = NumericBase::Decimal) 
				: Expression(ExpressionType::NumericLiteral), _text(text), _base(base), _numericType(type) { }

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
}