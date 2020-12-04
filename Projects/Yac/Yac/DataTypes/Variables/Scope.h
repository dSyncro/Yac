#pragma once

#include <unordered_map>

#include "Data.h"

namespace Yac::DataTypes {

	class Scope {

	public:

		Scope();
		Scope(Scope& parent);
		Scope(Scope* parent);

		const Scope& getParent() const noexcept { return *_parent; }

		Data findSelf(const std::string& identifier) const noexcept;

		Data findInHierarchy(const std::string& identifier) const noexcept;

		void set(const std::string& identifier, const Data& value) noexcept;

		static Scope* push(Scope* scope);
		static Scope* pop(Scope* scope);

	private:

		Scope* _parent;
		std::unordered_map<std::string, Yac::DataTypes::Data> _variables;
	};

}