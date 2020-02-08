#pragma once

namespace Yac {
	namespace DataTypes {

		class TypeSymbol {

		public:

			TypeSymbol(std::string name) : _name(name) {}

			friend bool operator ==(const TypeSymbol& a, const TypeSymbol& b) { return a._name == b._name; }

		private:

			std::string _name;
		};
	}
}