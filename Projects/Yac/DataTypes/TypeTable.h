#pragma once

#include <string>
#include <vector>

#include "TypeSymbol.h"

namespace Yac::DataTypes {

	class TypeTable final {

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
			TypeSymbol("bool"),
		};

	};
}