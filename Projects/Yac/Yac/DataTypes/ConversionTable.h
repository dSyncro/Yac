#pragma once

#include <string>
#include <unordered_map>

#include "Conversion.h"

namespace Yac::DataTypes {

	class ConversionTable final {

	public:

		void record(const Conversion& converter, ConversionHandler handler) noexcept
		{
			_table[converter] = handler;
		}

		bool contains(const Conversion& converter) const noexcept
		{
			auto it = _table.find(converter);
			return it != _table.end();
		}

	private:

		std::unordered_map<Conversion, ConversionHandler> _table;

	};
}