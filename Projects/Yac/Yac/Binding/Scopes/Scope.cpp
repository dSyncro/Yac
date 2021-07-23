#include "Scope.h"

#include <Yac/Binding/Scopes/NamespaceScope.h>

using namespace Yac;

Scope::Scope(ScopeType scopeType, Scope* parentScope)
	: _scopeType(scopeType), _parent(parentScope)
{
	if (parentScope)
		parentScope->children.push_back(this);
}

const TypeSymbol& Scope::findTypeOfIdentifier(const std::string& name) const
{
	const Scope* scope = this;
	do
	{
		const TypeSymbol& type = scope->identifiers.getType(name);
		if (type != TypeSymbol::getInvalidTypeSymbol())
			return type;

		scope = scope->_parent;
	} while (scope != nullptr);

	return TypeSymbol::getInvalidTypeSymbol();
}

const TypeSymbol& Scope::findTypeByName(const std::string& name) const
{
	const Scope* scope = this;
	do
	{
		if (scope->_scopeType == ScopeType::Namespace)
		{

			const NamespaceScope* ns = reinterpret_cast<const NamespaceScope*>(scope);
			const TypeSymbol& type = ns->types.get(name);

			if (type != TypeSymbol::getInvalidTypeSymbol())
				return type;
		}

		scope = scope->_parent;
	} while (scope != nullptr);

	return TypeSymbol::getInvalidTypeSymbol();
}

const TypeSymbol& Scope::findBinaryRetType(const BBinarySignature& signature) const
{
	const Scope* scope = this;
	do
	{
		if (scope->_scopeType == ScopeType::Namespace)
		{

			const NamespaceScope* ns = reinterpret_cast<const NamespaceScope*>(scope);
			const TypeSymbol& type = ns->binaryOperators.getReturnType(signature);

			if (type != TypeSymbol::getInvalidTypeSymbol())
				return type;
		}

		scope = scope->_parent;
	} while (scope != nullptr);

	return TypeSymbol::getInvalidTypeSymbol();
}