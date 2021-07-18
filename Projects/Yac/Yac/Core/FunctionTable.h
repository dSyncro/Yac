#pragma once

#include <unordered_map>

#include "FunctionSymbol.h"

#include <Yac/Core/FunctionOverload.h>

namespace Yac::Core {

	class FunctionTable {

	public:

		void bind(const std::string& name, const FunctionOverload& overload)
		{
			if (!hasBeenDeclared(name, overload))
				_functions[name].push_back(overload);
		}

		bool hasBeenDeclared(const std::string& name, const FunctionOverload& overload) const noexcept
		{
			auto it = _functions.find(name);

			if (it == _functions.end()) return false;

			const std::vector<FunctionOverload>& overloads = it->second;
			for (const FunctionOverload& ol : overloads)
				if (ol == overload) return true;
			return false;
		}

	private:

		std::unordered_map<std::string, std::vector<FunctionOverload>> _functions;
	};
}