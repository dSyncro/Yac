#pragma once

#include <string>

#include <Yac/Core/Primitives.h>

namespace Yac::Core {

	enum class VirtualType {
		Bool,
		Byte,
		Char,
		Short,
		Int,
		Long,
		UShort,
		UInt,
		ULong,
		String,
		Double,
		Float,
		Object,
		Void,
		Class
	};

	class TypeSymbol final {

	public:

		TypeSymbol() : _name("void"), _size(1) {}
		TypeSymbol(const std::string& name, IntT size) : _name(name), _size(size) {}

		bool operator ==(const TypeSymbol& other) const noexcept { return _name == other._name; }
		bool operator !=(const TypeSymbol& other) const noexcept { return _name != other._name; }

		const std::string& getName() const noexcept { return _name; }
		UIntT getSize() const noexcept { return _size; }

		static const TypeSymbol& getObjectTypeSymbol()
		{
			static TypeSymbol symbol = TypeSymbol("object", 1);
			return symbol;
		}

		static const TypeSymbol& getBoolTypeSymbol()
		{
			static TypeSymbol symbol = TypeSymbol("bool", 1);
			return symbol;
		}

		static const TypeSymbol& getDoubleTypeSymbol()
		{
			static TypeSymbol symbol = TypeSymbol("double", 8);
			return symbol;
		}

		static const TypeSymbol& getFloatTypeSymbol()
		{
			static TypeSymbol symbol = TypeSymbol("float", 4);
			return symbol;
		}

		static const TypeSymbol& getIntTypeSymbol()
		{
			static TypeSymbol symbol = TypeSymbol("int", 4);
			return symbol;
		}

		static const TypeSymbol& getUIntTypeSymbol()
		{
			static TypeSymbol symbol = TypeSymbol("uint", 4);
			return symbol;
		}

		static const TypeSymbol& getStringTypeSymbol()
		{
			static TypeSymbol symbol = TypeSymbol("string", sizeof(std::string));
			return symbol;
		}

		static const TypeSymbol& getVoidTypeSymbol()
		{
			static TypeSymbol symbol = TypeSymbol();
			return symbol;
		}

	private:

		std::string _name;
		UIntT _size;

	};
}