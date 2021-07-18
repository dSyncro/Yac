#pragma once

#include "Types/TypeSymbol.h"

#include <vector>

namespace Yac::Core {

	class FunctionSymbol final {

	public:

		FunctionSymbol(const std::string& name, const std::vector<std::reference_wrapper<TypeSymbol>>& parameters)
			: _name(name), _parameters(parameters) { }

		const std::string& getName() const noexcept { return _name; }
		const std::vector<std::reference_wrapper<TypeSymbol>> getParameters() const noexcept { return _parameters; }

		bool operator ==(const FunctionSymbol& other) const noexcept 
		{ 
			_name == other.getName() && 
			_parameters == other.getParameters(); 
		}

		bool operator !=(const FunctionSymbol other) const noexcept { return !(*this == other); }

	private:

		std::string _name;
		std::vector<std::reference_wrapper<TypeSymbol>> _parameters;
	};

}