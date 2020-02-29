#pragma once

#include <unordered_map>

#include <Syntax/Binding/BoundObject.h>

namespace Yac::Syntax {

	using namespace Yac::Syntax::Binding;

	class Scope {

	public:

		Scope() : _parent(nullptr) {}
		Scope(Scope& parent) : _parent(&parent) {}

		inline Scope* Parent() const noexcept { return _parent; }

		BoundObject* FindSelf(const std::string& identifier) const
		{
			auto it = _variables.find(identifier);
			return it == _variables.end() ? nullptr : it->second;
		}

		BoundObject* FindInHierarchy(const std::string& identifier) const
		{
			auto it = _variables.find(identifier);
			return it == _variables.end() ? (_parent ? _parent->FindInHierarchy(identifier) : nullptr) : it->second;
		}

		void Set(const std::string& identifier, BoundObject* value)
		{
			_variables[identifier] = value;
		}

	private:

		Scope* _parent;
		std::unordered_map<std::string, BoundObject*> _variables;
	};

}