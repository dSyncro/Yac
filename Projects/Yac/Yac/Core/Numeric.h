#pragma once

#include <variant>

#include <Yac/Core/Primitives.h>

namespace Yac {

	class Numeric : std::variant<IntT, UIntT, float, double> 
	{
	public:

		Numeric()
			: std::variant<IntT, UIntT, float, double>() {}

		template <typename T>
		Numeric(T value)
			: std::variant<IntT, UIntT, float, double>(value) {}

		template <typename T>
		T get() const { return std::get<T>(*this); }

		static Numeric parse(const std::string& text, NumericType type = NumericType::Int, NumericBase base = NumericBase::Decimal)
		{
			switch (type)
			{
				case NumericType::Int:
					return (IntT)std::stoi(text, nullptr, static_cast<UIntT>(base));
				case NumericType::UInt:
					return (UIntT)std::strtoul(&text[2], nullptr, static_cast<UIntT>(base));
				case NumericType::Float:
					return (float)std::stof(text);
				case NumericType::Double:
					return (double)std::stod(text);
				default: return Numeric();
			}
		}

		std::string toString(NumericType type = NumericType::Int)
		{
			switch (type)
			{
				case NumericType::Int: return std::to_string(get<IntT>());
				case NumericType::UInt: return std::to_string(get<UIntT>());
				case NumericType::Float: return std::to_string(get<float>());
				case NumericType::Double:  return std::to_string(get<double>());
				default: return "0";
			}
		}
	};

}