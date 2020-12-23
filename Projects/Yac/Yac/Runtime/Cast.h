#pragma once

#include <Yac/Core/Types/TypeSymbol.h>

namespace Yac::Runtime {

	struct Cast {

		Cast(const Core::TypeSymbol& from, const Core::TypeSymbol& to) : _fromType(&from), _toType(&to) {}

		const Core::TypeSymbol& getFromType() const noexcept { return *_fromType; }
		const Core::TypeSymbol& getToType() const noexcept { return *_toType; }

		bool operator ==(const Cast& other) const
		{
			return *_fromType == other.getFromType() && *_toType == other.getToType();
		}

	private:

		const Core::TypeSymbol* _fromType;
		const Core::TypeSymbol* _toType;
	};

}

namespace std {

	template<> struct hash<Yac::Runtime::Cast>
	{
		std::size_t operator()(const Yac::Runtime::Cast& cast) const noexcept
		{
			std::size_t h1 = std::hash<const Yac::Core::TypeSymbol*>{}(&cast.getFromType());
			std::size_t h2 = std::hash<const Yac::Core::TypeSymbol*>{}(&cast.getToType());
			return h1 ^ (h2 << 1);
		}
	};

}