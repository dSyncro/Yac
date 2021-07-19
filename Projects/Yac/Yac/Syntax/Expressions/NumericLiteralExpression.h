#pragma once

#include <Yac/Core/NumericBase.h>
#include <Yac/Core/NumericType.h>
#include <Yac/Syntax/Token.h>
#include <Yac/Syntax/Expressions/Expression.h>
#include <Yac/Core/Numeric.h>

namespace Yac {

	struct NumericLiteralExpression final : Expression {

	public:

		NumericLiteralExpression(const std::string& text, NumericType type, Core::NumericBase base = Core::NumericBase::Decimal)
			: Expression(ExpressionType::NumericLiteral), _numericType(type) 
		{ 
			switch (type)
			{
				case NumericType::Int:
					_number = (IntT)std::stoi(text, nullptr, static_cast<UIntT>(base));
					break;
				case NumericType::UInt:
					_number = (UIntT)std::stoul(text, nullptr, static_cast<UIntT>(base));
					break;
				case NumericType::Float:
					_number = (float)std::stof(text);
					break;
				case NumericType::Double:
					_number = (double)std::stod(text);
					break;
				default:
					_number = 0;
					break;
			}
		}

		template <typename T> 
		T getNumber() const { return std::get<T>(); }

		Numeric getNumeric() const noexcept { return _number; }
		NumericType getNumericType() const noexcept { return _numericType; }

	private:

		NumericType _numericType;
		Numeric _number;
	};

}