#pragma once

#include <string>

namespace Yac {
	namespace DataTypes {

		class TypeSymbol {

		public:

			TypeSymbol(std::string name) : _name(name) {}

			friend bool operator ==(const TypeSymbol& a, const TypeSymbol& b) { return a._name == b._name; }

			inline std::string name() const noexcept { return _name; }

		private:

			std::string _name;
		};
	}
}