#pragma once

#include <API/Object.h>
#include <DataTypes/Types/TypeSymbol.h>

namespace Yac::Syntax::Binding {

	struct BoundObject {

	public:

		BoundObject(const Yac::DataTypes::TypeSymbol& type, Yac::Api::Object* object) : _type(type), _object(object) {}

		~BoundObject()
		{
			delete _object;
		}

		const Yac::DataTypes::TypeSymbol& Type() const noexcept { return _type; }
		const Yac::Api::Object* Reference() const noexcept { return _object; }

	private:

		Yac::DataTypes::TypeSymbol _type;
		Yac::Api::Object* _object;
	};

}