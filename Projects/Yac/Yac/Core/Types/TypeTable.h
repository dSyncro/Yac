#pragma once

#include <string>
#include <vector>
#include <unordered_map>

#include "TypeSymbol.h"

namespace Yac {

	class TypeTable final {

	public:

		enum class DeclarationResult {
			Success,
			Failure,
			AlreadyDeclared
		};

		DeclarationResult declare(const std::string& name);

		void clear() noexcept { _table.clear(); }

		bool exists(const std::string& name) const noexcept;
		const TypeSymbol& get(const std::string& name) const noexcept;

	private:

		std::unordered_map<std::string, TypeSymbol> _table;

	};

	extern const TypeTable& getGlobalTypeTable();

}