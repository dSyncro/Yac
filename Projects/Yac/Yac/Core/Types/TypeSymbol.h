#pragma once

#include <string>

#include <Yac/Core/Base.h>

namespace Yac {

	class TypeSymbol final {

	public:

		TypeSymbol() : _name("void") {}
		TypeSymbol(const std::string& name) : _name(name) {}

		bool operator ==(const TypeSymbol& other) const noexcept { return _name == other._name; }
		bool operator !=(const TypeSymbol& other) const noexcept { return _name != other._name; }

		const std::string& getName() const noexcept { return _name; }

		static const TypeSymbol& getInvalidTypeSymbol() noexcept;

	private:

		std::string _name;

	};
}