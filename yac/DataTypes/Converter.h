#pragma once

#include "Data.h"

namespace Yac {
	namespace DataTypes {

		class Converter {

		public:

			Converter(const TypeSymbol& from, const TypeSymbol& to, Data(*callback)(const Yac::Api::Object*));

			Data Convert(const Data& data) const;

		private:

			const TypeSymbol& _from;
			const TypeSymbol& _to;
			Data(*_callback)(const Yac::Api::Object*);
		};

	}
}