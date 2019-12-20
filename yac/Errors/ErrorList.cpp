#include "ErrorList.h"

using namespace Yac::Errors;

void ErrorList::Add(const Error& e) noexcept { _errors.push_back(e); }

bool ErrorList::Any() const noexcept { return _errors.size() > 0; }

void ErrorList::Clear() noexcept { _errors.clear(); }

unsigned int ErrorList::Count() const noexcept { return _errors.size(); }

const Error& ErrorList::Get(unsigned int index) const
{
	if (index >= _errors.size()) throw;
	return _errors[index];
}

const Error& ErrorList::operator [](unsigned int index) const { return Get(index); }