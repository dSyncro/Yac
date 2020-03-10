#pragma once

#include <API/Object.h>
#include <DataTypes/Types/TypeSymbol.h>

namespace Yac::DataTypes {

	struct Data final {

	public:

		Data();
		Data(Yac::Api::Object* value);
		Data(const TypeSymbol& type, Yac::Api::Object* value);

		inline const TypeSymbol& type() const noexcept { return _type; }
		inline const Yac::Api::Object* value() const noexcept { return _value; }

		inline void Dispose() noexcept { delete _value; }

	private:

		TypeSymbol _type;
		Yac::Api::Object* _value;
	};

}