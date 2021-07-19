#include "NameTable.h"

using namespace Yac;

DeclarationResult NameTable::declare(const std::string& name, const TypeSymbol& type)
{
	if (exists(name))
		return DeclarationResult::AlreadyDeclared;

	bool result = _names.emplace(name, &type).second;
	return result ? DeclarationResult::Success : DeclarationResult::Failure;
}

bool NameTable::exists(const std::string& name) const noexcept
{
	auto it = _names.find(name);
	return it != _names.end();
}

const TypeSymbol& NameTable::getType(const std::string& name) const noexcept
{
	auto it = _names.find(name);

	if (it != _names.end())
		return *it->second;

	return TypeSymbol::getInvalidTypeSymbol();
}