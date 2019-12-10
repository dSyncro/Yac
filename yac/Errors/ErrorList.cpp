#include "ErrorList.h"

using namespace Yac::Errors;

const Error& ErrorList::Get(unsigned int index) const
{
	if (index >= _errors.size()) throw;
	return _errors[index];
}