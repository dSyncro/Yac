#pragma once

#include "TypedData.h"

namespace Yac::Runtime {

	struct Variable {

	public:

		Variable(const std::string& name, VariableData data) 
			: _name(name), _data(data) {};

		static bool referenceEqual(const Variable& a, const Variable& b) noexcept { return &a == &b; }

		void assign(VariableData data) noexcept { _data = data; }

		const VariableData getData() const noexcept { return _data; }
		const Core::TypeSymbol& getType() const noexcept { return _data.getType(); }
		const Api::Object* getValue() const noexcept { return _data.getValue(); }

		bool operator ==(const Variable& other) noexcept { return _name == other._name; }

	private:

		std::string _name;
		VariableData _data;
	};
}