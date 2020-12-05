#include "Scope.h"

using namespace Yac::Core;
using namespace Yac::Runtime;

Scope::Scope() : _parent(nullptr) {}
Scope::Scope(Scope& parent) : _parent(&parent) {}
Scope::Scope(Scope* parent) : _parent(parent) {}

TypedData Scope::findSelf(const std::string& identifier) const noexcept
{
	auto it = _variables.find(identifier);
	return it == _variables.end() ? TypedData() : it->second;
}

TypedData Scope::findInHierarchy(const std::string& identifier) const noexcept
{
	auto it = _variables.find(identifier);
	return it == _variables.end() ? (_parent ? _parent->findInHierarchy(identifier) : TypedData()) : it->second;
}

void Scope::set(const std::string& identifier, TypedData value) noexcept
{
	_variables[identifier] = value;
}

Scope* Scope::push(Scope* scope)
{
	return new Scope(scope);
}

Scope* Scope::pop(Scope* scope)
{
	Scope* parent = scope->_parent;
	delete scope;
	return parent ? parent : new Scope();
}