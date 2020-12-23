#pragma once

#include <string>
#include <vector>

#include "TypeSymbol.h"

namespace Yac::Core {

	class TypeTable final {

	public:

		void add(const TypeSymbol& symbol) noexcept
		{
			if (!contains(symbol))
				_table.push_back(symbol);
		}

		bool contains(const TypeSymbol& symbol) const noexcept
		{
			for (const TypeSymbol& s : _table)
				if (s == symbol) return true;
			return false;
		}

	private:

		std::vector<TypeSymbol> _table = {
			getObjectTypeSymbol(),
			getBoolTypeSymbol(),
			getDoubleTypeSymbol(),
			getFloatTypeSymbol(),
			getIntTypeSymbol(),
			getUIntTypeSymbol(),
			getStringTypeSymbol(),
			getVoidTypeSymbol()
		};

	};
}