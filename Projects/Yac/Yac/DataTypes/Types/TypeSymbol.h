#pragma once

#include <string>

namespace Yac::DataTypes {

	enum class BuiltinTypes {
		Bool,
		Byte,
		Char,
		Short,
		Int,
		Long,
		UShort,
		UInt,
		ULong,
		String
	};

	class TypeSymbol final {

	public:

		TypeSymbol() : _name("void") {}
		TypeSymbol(const std::string& name) : _name(name) {}

		friend bool operator ==(const TypeSymbol& a, const TypeSymbol& b);

		const std::string& getName() const noexcept { return _name; }

	private:

		std::string _name;
	};

	inline bool operator ==(const TypeSymbol& a, const TypeSymbol& b)
	{
		return a._name == b._name;
	}

	inline const TypeSymbol& getObjectTypeSymbol()
	{
		static TypeSymbol symbol = TypeSymbol("object");
		return symbol;
	}

	inline const TypeSymbol& getBoolTypeSymbol()
	{
		static TypeSymbol symbol = TypeSymbol("bool");
		return symbol;
	}

	inline const TypeSymbol& getDoubleTypeSymbol()
	{
		static TypeSymbol symbol = TypeSymbol("double");
		return symbol;
	}

	inline const TypeSymbol& getFloatTypeSymbol()
	{
		static TypeSymbol symbol = TypeSymbol("float");
		return symbol;
	}

	inline const TypeSymbol& getIntTypeSymbol()
	{
		static TypeSymbol symbol = TypeSymbol("int");
		return symbol;
	}

	inline const TypeSymbol& getUIntTypeSymbol()
	{
		static TypeSymbol symbol = TypeSymbol("uint");
		return symbol;
	}

	inline const TypeSymbol& getStringTypeSymbol()
	{
		static TypeSymbol symbol = TypeSymbol("string");
		return symbol;
	}

	inline const TypeSymbol& getVoidTypeSymbol()
	{
		static TypeSymbol symbol = TypeSymbol("void");
		return symbol;
	}
}