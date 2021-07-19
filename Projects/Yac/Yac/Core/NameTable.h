#pragma once

#include <unordered_map>

#include <Yac/Core/Types/TypeSymbol.h>
#include <Yac/Core/DeclarationResult.h>

namespace Yac {

	struct NameTable {

		DeclarationResult declare(const std::string& name, const TypeSymbol& type);

		bool exists(const std::string& name) const noexcept;
		const TypeSymbol& getType(const std::string& name) const noexcept;

	private:

		std::unordered_map<std::string, const TypeSymbol*> _names;
	};

}