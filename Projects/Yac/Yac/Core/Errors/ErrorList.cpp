#include "ErrorList.h"

using namespace Yac::Core;
using namespace Yac::Errors;

void ErrorList::add(const Error& e) noexcept { _errors.push_back(e); }

bool ErrorList::any() const noexcept { return _errors.size() > 0; }

void ErrorList::clear() noexcept { _errors.clear(); }

void ErrorList::reportUnexpectedToken(TokenType expected, TokenType found, const TextSpan& span) noexcept
{
	std::string msg = "Expected <" + toString(expected) + "> token, <" + toString(found) + "> found";
	_errors.emplace_back(msg, span);
}

void ErrorList::reportUnknownToken(char c, const TextSpan& span) noexcept
{
	std::string msg = "Found unknown token '" + c;
	msg.append("'");
	_errors.emplace_back(msg, span);
}

void ErrorList::reportNotABooleanLiteral(const std::string& text, const TextSpan& span) noexcept
{
	std::string msg = "'" + text + "' is not a valid Boolean literal";
	_errors.emplace_back(msg, span);
}

std::size_t ErrorList::count() const noexcept { return _errors.size(); }

const Error& ErrorList::get(UIntT index) const
{
	if (index >= _errors.size()) throw;
	return _errors[index];
}

const Error& ErrorList::operator [](UIntT index) const { return get(index); }