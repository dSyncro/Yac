#pragma once

#include <Yac/API/Object.h>
#include <Yac/Core/Types/TypeSymbol.h>

namespace Yac::Runtime {

	struct TypedData {

	public:

		TypedData(const Core::TypeSymbol& type = Core::getVoidTypeSymbol(), Api::Object* value = nullptr)
			: _type(&type), _value(value) { }

		const Core::TypeSymbol& getType() const noexcept { return *_type; }
		Api::Object* getValue() const noexcept { return _value; }

	private:

		const Core::TypeSymbol* _type;
		Api::Object* _value;
	};
}