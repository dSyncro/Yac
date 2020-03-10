#include "Scope.h"

using namespace Yac::DataTypes;

Scope::Scope() : _parent(nullptr) {}
Scope::Scope(Scope& parent) : _parent(&parent) {}
Scope::Scope(Scope* parent) : _parent(parent) {}

Data Scope::FindSelf(const std::string& identifier) const noexcept
{
	auto it = _variables.find(identifier);
	return it == _variables.end() ? nullptr : it->second;
}

Data Scope::FindInHierarchy(const std::string& identifier) const noexcept
{
	auto it = _variables.find(identifier);
	return it == _variables.end() ? (_parent ? _parent->FindInHierarchy(identifier) : Yac::DataTypes::Data()) : it->second;
}

void Scope::Set(const std::string& identifier, const Data& value) noexcept
{
	_variables[identifier] = value;
}

Scope* Scope::Push(Scope* scope)
{
	return new Scope(scope);
}

Scope* Scope::Pop(Scope* scope)
{
	Scope* parent = scope->_parent;
	delete scope;
	return parent ? parent : new Scope();
}