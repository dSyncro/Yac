#include "Scope.h"

using namespace Yac::Core;
using namespace Yac::Runtime;

Scope::Scope(Scope* parent) : _parent(parent) {}

VariableData Scope::findSelf(const std::string& identifier) const noexcept
{
	auto it = _variables.find(identifier);
	return it == _variables.end() ? VariableData() : it->second;
}

VariableData Scope::findInHierarchy(const std::string& identifier) const noexcept
{
	auto it = _variables.find(identifier);
	return it == _variables.end() ? (_parent ? _parent->findInHierarchy(identifier) : VariableData()) : it->second;
}

void Scope::set(const std::string& identifier, VariableData value) noexcept
{
	_variables[identifier] = value;
}

Scope* Scope::pushTo(Scope* scope)
{
	return new Scope(scope);
}

Scope* Scope::popFrom(Scope* scope)
{
	Scope* parent = scope->_parent;
	delete scope;
	return parent ? parent : new Scope();
}