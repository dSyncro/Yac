#pragma once

#include "Types/TypeSymbol.h"

namespace Yac::Core {

	class ParameterSymbol final {

		ParameterSymbol(const TypeSymbol& type, const std::string& name)
			: _type(&type), _name(name) { }

		const TypeSymbol& getType() const noexcept { return *_type; }
		const std::string& getName() const noexcept { return _name; }

	private:

		const TypeSymbol* _type;
		std::string _name;
	};

}