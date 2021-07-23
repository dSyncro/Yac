#pragma once

#include <vector>

#include "ScopeType.h"

#include <Yac/Binding/BBinarySignature.h>
#include <Yac/Core/NameTable.h>

namespace Yac {

	struct Scope {

		Scope(Scope* parentScope = nullptr)
			: Scope(ScopeType::Generic, parentScope) { }

		virtual ~Scope()
		{
			for (std::size_t i = 0; i < children.size(); i++)
				delete children[i];
		}

		std::vector<Scope*> children;

		NameTable identifiers; // Variables can be declared in any scope

		const TypeSymbol& findTypeOfIdentifier(const std::string& name) const;
		const TypeSymbol& findTypeByName(const std::string& name) const;
		const TypeSymbol& findBinaryRetType(const BBinarySignature& signature) const;

		ScopeType getScopeType() const noexcept { return _scopeType; }
		Scope* getParent() const noexcept { return _parent; }

	protected:

		Scope* _parent;
		ScopeType _scopeType;

		Scope(ScopeType scopeType, Scope* parentScope = nullptr);

	};
}