#pragma once

#include <DataTypes/ConversionTable.h>
#include <DataTypes/Types/TypeTable.h>

namespace Yac::Syntax {

	class NameTable {

	public:

		bool HasBeenDeclared(const Yac::DataTypes::TypeSymbol& symbol) const noexcept;
		bool HasBeenDeclared(const Yac::DataTypes::Conversion& conversion) const noexcept;

		void Register(const Yac::DataTypes::TypeSymbol& symbol) noexcept;
		void Register(const Yac::DataTypes::Conversion& conversion, Yac::DataTypes::ConversionHandler handler) noexcept;

	private:

		Yac::DataTypes::TypeTable _types;
		Yac::DataTypes::ConversionTable _converters;
	};

}