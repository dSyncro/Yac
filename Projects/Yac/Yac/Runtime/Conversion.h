#pragma once

#include <functional>
#include <string>
#include <unordered_map>

#include "TypedData.h"
#include <Yac/API/Object.h>

namespace Yac::Runtime {

	using Converter = Runtime::TypedData(*)(const Api::Object*);

	struct Cast {

		const Core::TypeSymbol* fromType;
		const Core::TypeSymbol* toType;

		Cast(const Core::TypeSymbol& from, const Core::TypeSymbol& to) : fromType(&from), toType(&to) {}

		bool operator ==(const Cast& other) const
		{
			return this == &other || (fromType == other.fromType && toType == other.toType);
		}
	};

}

namespace std {

	template<> struct hash<Yac::Runtime::Cast>
	{
		std::size_t operator()(const Yac::Runtime::Cast& cast) const noexcept
		{
			std::size_t h1 = std::hash<const Yac::Core::TypeSymbol*>{}(cast.fromType);
			std::size_t h2 = std::hash<const Yac::Core::TypeSymbol*>{}(cast.toType);
			return h1 ^ (h2 << 1);
		}
	};

}

namespace Yac::Runtime {

	class ConversionTable final {

	public:

		void record(Cast cast, Converter converter) noexcept
		{
			_table[cast] = converter;
		}

		bool contains(const Cast& cast) const noexcept
		{
			auto it = _table.find(cast);
			return it != _table.end();
		}

	private:

		std::unordered_map<Cast, Converter> _table;

	};
}
