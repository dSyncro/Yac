#pragma once

#include <unordered_map>

#include "Data.h"

namespace Yac::DataTypes {

	class Scope {

	public:

		Scope();
		Scope(Scope& parent);
		Scope(Scope* parent);

		inline const Scope& Parent() const noexcept { return *_parent; }

		Data FindSelf(const std::string& identifier) const noexcept;

		Data FindInHierarchy(const std::string& identifier) const noexcept;

		void Set(const std::string& identifier, const Data& value) noexcept;

		static Scope* Push(Scope* scope);
		static Scope* Pop(Scope* scope);

	private:

		Scope* _parent;
		std::unordered_map<std::string, Yac::DataTypes::Data> _variables;
	};

}