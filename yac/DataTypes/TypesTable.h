#pragma once

#include <string>
#include <vector>

namespace Yac {
	namespace DataTypes {

		class TypeSymbol {

		public:

			TypeSymbol(std::string name) : _name(name) {}

			friend bool operator ==(const TypeSymbol& a, const TypeSymbol& b) { return a._name == b._name; }

		private:

			std::string _name;
		};

		class TypeTable {

		public:

			void Register(const TypeSymbol& symbol) noexcept
			{
				if (!Contains(symbol))
					_table.push_back(symbol);
			}

			bool Contains(const TypeSymbol& symbol) const noexcept
			{
				for (const TypeSymbol& s : _table)
					if (s == symbol) return true;
				return false;
			}

		private:

			std::vector<TypeSymbol> _table = {
				TypeSymbol("int"),
				TypeSymbol("uint"),
				TypeSymbol("float"),
				TypeSymbol("double"),
			};

		};
	}
}