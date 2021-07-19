#include "TypeTable.h"

using namespace Yac;

DeclarationResult TypeTable::declare(const std::string& name)
{
	if (exists(name))
		return DeclarationResult::AlreadyDeclared;

	bool result = _table.emplace(name, TypeSymbol(name)).second;
	return result ? DeclarationResult::Success : DeclarationResult::Failure;
}

bool TypeTable::exists(const std::string& name) const noexcept
{
	auto it = _table.find(name);
	return it != _table.end();
}

const TypeSymbol& TypeTable::get(const std::string& name) const noexcept
{
	auto it = _table.find(name);

	// null is a reserved keyword therefore no type might be called after it
	if (it == _table.end())
		return TypeSymbol::getInvalidTypeSymbol();

	return it->second;
}