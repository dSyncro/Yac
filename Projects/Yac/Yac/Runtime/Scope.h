#pragma once

#include <unordered_map>

#include "TypedData.h"

namespace Yac::Runtime {

	class Scope {

	public:

		Scope();
		Scope(Scope& parent);
		Scope(Scope* parent);

		const Scope& getParent() const noexcept { return *_parent; }

		TypedData findSelf(const std::string& identifier) const noexcept;

		TypedData findInHierarchy(const std::string& identifier) const noexcept;

		void set(const std::string& identifier, TypedData value) noexcept;

		static Scope* push(Scope* scope);
		static Scope* pop(Scope* scope);

	private:

		Scope* _parent;
		std::unordered_map<std::string, TypedData> _variables;
	};

}