#pragma once

#include <string>
#include <unordered_map>

#include "Conversion.h"

namespace Yac::DataTypes {

	class ConversionTable final {

	public:

		void Register(const Conversion& converter, ConversionHandler handler) noexcept
		{
			_table[converter] = handler;
		}

		bool Contains(const Conversion& converter) const noexcept
		{
			std::unordered_map<Conversion, ConversionHandler>::const_iterator it = _table.find(converter);
			return it != _table.end();
		}

	private:

		std::unordered_map<Conversion, ConversionHandler> _table;

	};
}