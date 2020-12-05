#pragma once

#include "TypedData.h"

namespace Yac::Runtime {

	struct Variable {

	public:

		Variable(const std::string& name, TypedData data) 
			: _name(name), _data(data) {};

		static bool referenceEqual(const Variable& a, const Variable& b) noexcept { return &a == &b; }

		void assign(TypedData data) noexcept { _data = data; }

		const TypedData getData() const noexcept { return _data; }
		const Core::TypeSymbol& getType() const noexcept { return _data.getType(); }
		const Api::Object* getValue() const noexcept { return _data.getValue(); }

		bool operator ==(const Variable& other) noexcept { return _name == other._name; }

	private:

		std::string _name;
		TypedData _data;
	};
}