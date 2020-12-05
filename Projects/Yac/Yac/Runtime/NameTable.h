#pragma once

#include "Conversion.h"
#include <Yac/Core/Types/TypeTable.h>

namespace Yac::Runtime {

	class NameTable {

	public:

		bool hasBeenDeclared(const Core::TypeSymbol& symbol) const noexcept;
		bool hasBeenDeclared(Cast cast) const noexcept;

		void record(const Core::TypeSymbol& symbol) noexcept;
		void record(Cast cast, Converter handler) noexcept;

	private:

		Core::TypeTable _types;
		ConversionTable _converters;
	};

}