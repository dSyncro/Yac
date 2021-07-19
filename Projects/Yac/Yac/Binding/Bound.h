#pragma once

#include <Yac/Core/Types/TypeSymbol.h>

namespace Yac {

	template <typename T>
	class Bound {

	public:

		Bound(const T& value, const TypeSymbol& type)
			: _value(value), _type(&type) { }

		const T& getValue() const noexcept { return _value; }
		const TypeSymbol& getType() const noexcept { return _type; }

	private:

		T _value;
		const TypeSymbol* _type;
	};
}