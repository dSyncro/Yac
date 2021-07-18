#pragma once

#include <cctype>

struct Char {

public:

	constexpr Char(const char c) : _c(c) {}

	bool isLetter() const noexcept { return std::isalpha(_c); }
	bool isAlphanum() const noexcept { return std::isalnum(_c); }
	bool isControl() const noexcept { return std::iscntrl(_c); }
	bool isBlank() const noexcept { return std::isblank(_c); }
	bool isGraphic() const noexcept { return std::isgraph(_c); }
	bool isLower() const noexcept { return std::islower(_c); }
	bool isPrintable() const noexcept { return std::isprint(_c); }
	bool isPuntation() const noexcept { return std::ispunct(_c); }
	bool isSpace() const noexcept { return std::isspace(_c); }
	bool isUpper() const noexcept { return std::isupper(_c); }
	bool isHexDigit() const noexcept { return std::isxdigit(_c); }
	bool isDigit() const noexcept { return std::isdigit(_c); }

	operator char() const { return _c; }

private:

	char _c;
};