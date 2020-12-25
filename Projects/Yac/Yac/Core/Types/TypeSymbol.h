#pragma once

#include <string>

#include <Yac/Core/Primitives.h>

namespace Yac::Core {

	class TypeSymbol final {

	public:

		TypeSymbol() : _name("void"), _size(1) {}
		TypeSymbol(const std::string& name, IntT size) : _name(name), _size(size) {}

		bool operator ==(const TypeSymbol& other) const noexcept { return _name == other._name; }
		bool operator !=(const TypeSymbol& other) const noexcept { return _name != other._name; }

		const std::string& getName() const noexcept { return _name; }
		UIntT getSize() const noexcept { return _size; }

		// Primitives

		static const TypeSymbol& getByteTypeSymbol();
		static const TypeSymbol& getBoolTypeSymbol();
		static const TypeSymbol& getCharTypeSymbol();
		static const TypeSymbol& getDoubleTypeSymbol();
		static const TypeSymbol& getFloatTypeSymbol();
		static const TypeSymbol& getShortTypeSymbol();
		static const TypeSymbol& getUShortTypeSymbol();
		static const TypeSymbol& getIntTypeSymbol();
		static const TypeSymbol& getUIntTypeSymbol();
		static const TypeSymbol& getLongTypeSymbol();
		static const TypeSymbol& getULongTypeSymbol();

		static const TypeSymbol& getObjectTypeSymbol();
		static const TypeSymbol& getStringTypeSymbol();
		static const TypeSymbol& getVoidTypeSymbol();

	private:

		std::string _name;
		UIntT _size;

	};

	template <typename T>
	const TypeSymbol& toTypeSymbol()
	{
		//else if constexpr (std::is_same_v<T, std::string>)
		//	return Core::getStringTypeSymbol();

		//else if constexpr (std::is_same_v<T, void>)
		//	return Core::TypeSymbol::getVoidTypeSymbol();

		//else if constexpr (std::is_same_v<T, void*>)
		//	return Core::getClassTypeSymbol();

		return TypeSymbol::getObjectTypeSymbol();
	}

	template<> const TypeSymbol& toTypeSymbol<ByteT>();
	template<> const TypeSymbol& toTypeSymbol<bool>();
	template<> const TypeSymbol& toTypeSymbol<float>();
	template<> const TypeSymbol& toTypeSymbol<double>();
	template<> const TypeSymbol& toTypeSymbol<ShortT>();
	template<> const TypeSymbol& toTypeSymbol<UShortT>();
	template<> const TypeSymbol& toTypeSymbol<IntT>();
	template<> const TypeSymbol& toTypeSymbol<UIntT>();
	template<> const TypeSymbol& toTypeSymbol<LongT>();
	template<> const TypeSymbol& toTypeSymbol<ULongT>();
}