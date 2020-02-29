#pragma once

#include <functional>

#include <DataTypes/Types/TypeSymbol.h>
#include <DataTypes/Variables/Data.h>

namespace Yac::DataTypes {

	using ConversionHandler = Data(*)(const Yac::Api::Object*);

	struct Conversion {

		TypeSymbol From;
		TypeSymbol To;

		Conversion(TypeSymbol from, TypeSymbol to) : From(from), To(to) {}

        bool operator==(const Conversion& other) const
        {
            return this == &other || (From == other.From && To == other.To);
        }
	};

}

namespace std {
    template<> struct hash<Yac::DataTypes::Conversion>
    {
        std::size_t operator()(const Yac::DataTypes::Conversion& conversion) const noexcept
        {
            std::size_t h1 = std::hash<std::string>{}(conversion.From.name());
            std::size_t h2 = std::hash<std::string>{}(conversion.To.name());
            return h1 ^ (h2 << 1);
        }
    };
}