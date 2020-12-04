#pragma once

#include <Yac/DataTypes/ConversionTable.h>
#include <Yac/DataTypes/Types/TypeTable.h>

namespace Yac::Syntax {

	class NameTable {

	public:

		bool hasBeenDeclared(const Yac::DataTypes::TypeSymbol& symbol) const noexcept;
		bool hasBeenDeclared(const Yac::DataTypes::Conversion& conversion) const noexcept;

		void record(const Yac::DataTypes::TypeSymbol& symbol) noexcept;
		void record(const Yac::DataTypes::Conversion& conversion, Yac::DataTypes::ConversionHandler handler) noexcept;

	private:

		Yac::DataTypes::TypeTable _types;
		Yac::DataTypes::ConversionTable _converters;
	};

}