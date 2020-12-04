#pragma once

#include <functional>

#include <Yac/DataTypes/Types/TypeSymbol.h>
#include <Yac/DataTypes/Variables/Data.h>

namespace Yac::DataTypes {

	using ConversionHandler = Data(*)(const Yac::Api::Object*);

	struct Conversion {

		TypeSymbol from;
		TypeSymbol to;

		Conversion(TypeSymbol from, TypeSymbol to) : from(from), to(to) {}

        bool operator ==(const Conversion& other) const
        {
            return this == &other || (from == other.from && to == other.to);
        }
	};

}

namespace std {
    template<> struct hash<Yac::DataTypes::Conversion>
    {
        std::size_t operator()(const Yac::DataTypes::Conversion& conversion) const noexcept
        {
            std::size_t h1 = std::hash<std::string>{}(conversion.from.getName());
            std::size_t h2 = std::hash<std::string>{}(conversion.to.getName());
            return h1 ^ (h2 << 1);
        }
    };
}