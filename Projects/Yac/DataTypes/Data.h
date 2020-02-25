#pragma once

#include "TypeSymbol.h"

#include <API/Object.h>

namespace Yac::DataTypes {

	struct Data final {

	public:

		Data(const TypeSymbol& type, Yac::Api::Object* value);
		~Data();

		inline const TypeSymbol& type() const noexcept { return *_type; }
		inline const Yac::Api::Object* value() const noexcept { return _value; }

		inline void Dispose() noexcept { delete _value; }

	private:

		const TypeSymbol* _type;
		Yac::Api::Object* _value;
	};

}