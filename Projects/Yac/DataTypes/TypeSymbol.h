#pragma once

#include <string>

namespace Yac::DataTypes {

	class TypeSymbol final {

	public:

		TypeSymbol(std::string name) : _name(name) {}

		friend bool operator ==(const TypeSymbol& a, const TypeSymbol& b) 
		{ 
			return &a == &b || a._name == b._name; 
		}

		inline std::string name() const noexcept { return _name; }

	private:

		std::string _name;
	};
}