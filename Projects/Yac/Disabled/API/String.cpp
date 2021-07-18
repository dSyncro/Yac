#include <cstring>
#include <stdexcept>
#include <memory>

#include "String.h"

using namespace Yac::Api;

String::String() : _buffer(nullptr), _length(0) {}

String::String(char c) : _length(1)
{
	// Allocate a single char and assign it
	_buffer = new char[1];
	_buffer[0] = c;
}

String::String(char c, UInt amount)
	: _length(amount)
{
	_buffer = new char[amount];
	for (UInt i = 0; i < amount; ++i)
		_buffer[i] = c;
}

String::String(char* chars, UInt length)
	: _buffer(chars), _length(length) {}

String::String(const char* string)
{
	// if string is not valid
	if (!string)
	{
		_length = 0;
		_buffer = nullptr;
		return;
	}

	_length = std::strlen(string);

	char* buffer = new char[_length];
	std::memcpy(buffer, string, _length);

	_buffer = buffer;
}

String::String(const std::string& string)
	: _length(string.size())
{
	_buffer = new char[_length];
	std::memcpy(_buffer, string.data(), _length);
}

String::String(const String& string) : _length(string._length)
{
	_buffer = new char[_length];
	std::memcpy(_buffer, string._buffer, _length);
}

String::~String()
{
	// Just release the buffer
	delete[] _buffer;
}

UInt String::count(char c) const noexcept
{
	UInt count = 0;
	for (UInt i = 0; i < _length; i++)
		if (_buffer[i] == c) count++;

	return count;
}

UInt String::count(const String& substring) const noexcept
{
	// if substring is longer than string, there is no occurence
	if (substring.length() > _length) return 0;

	UInt count = 0;

	// same as before
	// no need to check for occurrencies when substring
	// is longer than remaining string
	UInt gap = _length - substring.length();
	for (UInt i = 0; i <= gap; i++)
	{
		// if different continue
		if (_buffer[i] != substring[0]) continue;

		// i is string index
		// j is substring index
		UInt j;

		// compare the two
		for (j = 1; j < substring.length(); j++)
			if (_buffer[i + j] != substring[j]) break;
		
		// if all chars were equal, we found an occurrence
		if (j == substring.length()) count++;
	}

	return count;
}

UInt String::firstIndexOf(char c) const noexcept
{
	for (UInt i = 0; i < _length; i++)
		if (_buffer[i] == c) return i;

	return UInt::infinity();
}

UInt String::firstIndexOf(const String& substring) const noexcept
{
	// Same logic as String::count(const String&)

	if (substring.length() > _length) return 0xFFFFFFFF;

	UInt gap = _length - substring.length();
	for (UInt i = 0; i <= gap; i++)
	{
		if (_buffer[i] != substring[0]) continue;

		UInt j;
		for (j = 1; j < substring.length(); j++)
			if (_buffer[i + j] != substring[j]) break;

		if (j == substring.length()) return i;
	}

	return UInt::infinity();
}

UInt String::lastIndexOf(char c) const noexcept
{
	for (UInt i = _length - 1; i >= 0; i--)
		if (_buffer[i] == c) return i;

	return UInt::infinity();
}

UInt String::lastIndexOf(const String& substring) const noexcept
{
	// if substring is longer than string, there is no occurence
	if (substring.length() > _length) 
		return UInt::infinity();

	// same as before
	// no need to check for occurrencies when substring
	// is longer than remaining string
	UInt gap = _length - substring.length();
	for (UInt i = _length - 1; i > gap; --i)
	{
		// if different continue
		if (_buffer[i] != substring[substring.length() - 1]) continue;

		// i is string index
		// j is substring index
		UInt j;

		// compare the two
		for (j = substring.length() - 1; j; --j)
			if (_buffer[i + substring.length() - j] != substring[j]) break;

		// if all chars are equal, we found an occurrence
		if (j == 0 && _buffer[i + substring.length()] == substring[j])
			return i;
	}

	return UInt::infinity();
}

bool String::contains(char c) const noexcept
{
	for (UInt i = 0; i < _length; ++i)
		if (_buffer[i] == c) return true;

	return false;
}

bool String::contains(const String& substring) const noexcept
{
	// Same logic as String::count(const String&)

	if (substring.length() > _length) return false;

	UInt gap = _length - substring.length();
	for (UInt i = 0; i <= gap; ++i)
	{
		if (_buffer[i] != substring[0]) continue;

		UInt j;
		for (j = 1; j < substring.length(); j++)
			if (_buffer[i + j] != substring[j]) break;

		if (j == substring.length()) return true;
	}

	return false;
}

bool String::isAlphabet() const noexcept
{
	for (UInt i = 0; i < _length; ++i)
	{
		bool isUpperOrLower = ('A' <= _buffer[i] && _buffer[i] <= 'Z') ||
			('a' <= _buffer[i] && _buffer[i] <= 'z');
		if (!isUpperOrLower) return false;
	}

	return true;
}

bool String::isAlphanum() const noexcept
{
	for (UInt i = 0; i < _length; ++i)
	{
		bool isAlphanumeric = ('A' <= _buffer[i] && _buffer[i] <= 'Z') ||
			('a' <= _buffer[i] && _buffer[i] <= 'z') ||
			('0' <= _buffer[i] && _buffer[i] <= '9');
		if (!isAlphanumeric) return false;
	}

	return true;
}

bool String::isNumber() const noexcept
{
	for (UInt i = 0; i < _length; ++i)
	{
		bool numberRange = '0' <= _buffer[i] && _buffer[i] <= '9';
		if (!numberRange) return false;
	}

	return true;
}

bool String::isLower() const noexcept
{
	for (UInt i = 0; i < _length; ++i)
	{
		bool upperRange = 'A' <= _buffer[i] && _buffer[i] <= 'Z';
		if (upperRange) return false;
	}

	return true;
}

bool String::isUpper() const noexcept
{
	for (UInt i = 0; i < _length; ++i)
	{
		bool lowerRange = 'a' <= _buffer[i] && _buffer[i] <= 'z';
		if (lowerRange) return false;
	}

	return true;
}

String String::substring(UInt start, UInt length) const
{
	if (start >= _length) return *this;
	if (length > _length - start) 
		length = _length - start;

	char* buffer = new char[length];
	std::memcpy(buffer, _buffer + start, length);

	return String(buffer, length);
}

String String::strip() const noexcept
{
	UInt start = 0;
	for (start; start < _length; ++start)
		if (!std::isblank(_buffer[start])) break;

	UInt end = _length - 1;
	for (end; end; --end)
		if (!std::isblank(_buffer[end])) break;

	UInt count = end - start + 1;
	return substring(start, count);
}

String String::strip(char c) const noexcept
{
	// get start point
	UInt start = 0;
	for (start; start < _length; ++start)
		if (_buffer[start] != c) break;

	// get end point
	UInt end = _length - 1;
	for (end; end; --end)
		if (_buffer[end] != c) break;

	// calculate new string length
	UInt count = end - start + 1;

	// new string is actually a substring of this string
	return substring(start, count);
}

String String::lStrip() const noexcept
{
	UInt i = 0;
	for (i; i < _length; ++i)
		if (!std::isblank(_buffer[i])) break;

	return substring(i, _length - i);
}

String String::lStrip(char c) const noexcept
{
	// get start point
	UInt i = 0;
	for (i; i < _length; ++i)
		if (_buffer[i] != c) break;

	// new string is actually a substring of this string
	return substring(i, _length - i);
}

String String::rStrip() const noexcept
{
	UInt i = _length - 1;
	for (i; i; --i)
		if (!std::isblank(_buffer[i])) break;

	// If are exactly equal just return a copy of this
	if (i == 0 && std::isblank(_buffer[i]))
		return *this;

	return substring(0, i + 1);
}

String String::rStrip(char c) const noexcept
{
	// get end point
	UInt i = _length - 1;
	for (i; i; --i)
		if (_buffer[i] != c) break;

	// If are exactly equal just return a copy of this
	if (i == 0 && _buffer[i] == c)
		return *this;

	// new string is actually a substring of this string
	return substring(0, i + 1);
}

String String::remove(char c) const noexcept
{
	UInt counter = count(c);
	if (counter == 0) return *this;

	UInt newLength = _length - counter;
	char* newBuffer = new char[newLength];

	UInt offset = 0;
	for (UInt i = 0; i < newLength; ++i)
	{
		if (_buffer[i + offset] == c) ++offset;
		newBuffer[i] = _buffer[i + offset];
	}

	return String(newBuffer, newLength);
}

String String::removeAt(UInt index) const
{
	UInt len = _length - 1;
	char* buffer = new char[len];

	// copy up to index
	std::memcpy(buffer, _buffer, index);
	// skip char at index and copy to the end
	std::memcpy(buffer + index, _buffer + index + 1, len - index);

	return String(buffer, len);
}

String String::removeFirst(char c) const noexcept
{
	UInt index = firstIndexOf(c);

	// if not found just copy this
	if (index == UInt::infinity()) 
		return *this;

	return removeAt(index);
}

String String::removeLast(char c) const noexcept
{
	UInt index = lastIndexOf(c);
	if (index == UInt::infinity()) return *this;

	return removeAt(index);
}

String String::replaceAt(UInt index, char c) const
{
	String s = *this;
	s[index] = c;
	return s;
}

String String::replaceFirst(char before, char after) const noexcept
{
	UInt index = firstIndexOf(before);

	// if not found just copy this
	if (index == UInt::infinity()) 
		return *this;

	return replaceAt(index, after);
}

String String::replaceLast(char before, char after) const noexcept
{
	UInt index = lastIndexOf(before);

	// if not found just copy this
	if (index == UInt::infinity()) 
		return *this;

	return replaceAt(index, after);
}

String String::replaceAll(char before, char after) const noexcept
{
	String s = *this;

	for (UInt i = 0; i < _length; ++i)
		if (s[i] == before) s[i] = after;

	return s;
}

String String::toLower() const noexcept
{
	char* buffer = new char[_length];
	for (UInt i = 0; i < _length; ++i)
	{
		char charAtIndex = _buffer[i];
		if (charAtIndex >= 'A' && charAtIndex <= 'Z')
			buffer[i] = charAtIndex - ('Z' - 'z');
		else buffer[i] = charAtIndex;
	}

	return String(buffer, _length);
}

String String::toUpper() const noexcept
{
	char* buffer = new char[_length];
	for (UInt i = 0; i < _length; ++i)
	{
		char charAtIndex = _buffer[i];
		if (charAtIndex >= 'a' && charAtIndex <= 'z')
			buffer[i] = charAtIndex - ('z' - 'Z');
		else buffer[i] = charAtIndex;
	}

	return String(buffer, _length);
}

String String::toggleCase() const noexcept
{
	char* buffer = new char[_length];
	for (UInt i = 0; i < _length; ++i)
	{
		char charAtIndex = _buffer[i];
		if (charAtIndex >= 'a' && charAtIndex <= 'z')
			buffer[i] = charAtIndex - ('z' - 'Z');
		else if (charAtIndex >= 'A' && charAtIndex <= 'Z')
			buffer[i] = charAtIndex - ('Z' - 'z');
		else buffer[i] = charAtIndex;
	}

	return String(buffer, _length);
}

StringList String::split(char c) const
{
	StringList strings;

	// remove useless separators
	String s = strip(c);

	UInt count = s.count(c);
	if (!count) return strings;

	UInt lastIndexOf = 0;
	strings.resize(count + 1);

	count = 0;
	for (UInt i = 0; i < _length; ++i)
	{
		if (s._buffer[i] != c) continue;

		strings[count] = s.substring(lastIndexOf, i - lastIndexOf);
		lastIndexOf = i + 1;
		count++;
	}

	strings[count] = s.substring(lastIndexOf, _length - lastIndexOf);

	return strings;
}

const String& String::empty() noexcept
{
	static String s;
	return s;
}

String& String::operator =(const String& string)
{
	if (this == &string) return *this;

	_length = string._length;

	char* buffer = new char[_length];
	std::memcpy(buffer, string._buffer, _length);

	delete[] _buffer;
	_buffer = buffer;

	return *this;
}

String& String::operator +=(const String& string)
{
	UInt length = _length + string._length;
	char* finalBuffer = new char[length];

	std::memcpy(finalBuffer, _buffer, _length);
	std::memcpy(finalBuffer + _length, string._buffer, string._length);

	_length = length;

	delete[] _buffer;
	_buffer = finalBuffer;

	return *this;
}

String& String::operator *=(UInt n)
{
	UInt finalLength = _length * n;
	char* finalBuffer = new char[finalLength];

	for (UInt i = 0; i < n; ++i)
		std::memcpy(finalBuffer + i * _length, _buffer, _length);

	_length = finalLength;

	delete[] _buffer;
	_buffer = finalBuffer;

	return *this;
}

String operator +(const String& a, const String& b) { return String(a) += b; }
String operator +(const String& string, char c) { return String(string) += String(c); }
String operator +(const String& string, const char* other) { return String(string) += String(other); }
String operator +(char a, const String& b) { return String(a) += b; }
String operator +(const char* a, const String& b) { return String(a) += b; }

String operator *(const String& string, UInt n)
{
	UInt finalLength = string._length * n;
	char* finalBuffer = new char[finalLength];

	for (UInt i = 0; i < n; ++i)
		std::memcpy(finalBuffer + i * string._length, string._buffer, string._length);

	return String(finalBuffer, finalLength);
}

String operator *(UInt n, const String& str) { return str * n; }

bool operator ==(const String& a, const String& b)
{
	if (a.length() != b.length()) return false;

	for (UInt i = 0; i < a.length(); ++i)
		if (a[i] != b[i]) return false;

	return true;
}

bool operator ==(const String& a, const char* b)
{
	if (a.length() != std::strlen(b)) return false;

	for (UInt i = 0; i < a.length(); ++i)
		if (a[i] != b[i]) return false;

	return true;
}

bool operator ==(const char* a, const String& b)
{
	return b == a;
}

bool operator ==(const String& string, char c)
{
	if (string.length() != 1) return false;
	return (string[0] == c) ? true : false;
}

bool operator ==(char c, const String& string) { return string == c; }

bool operator !=(const String& a, const String& b) { return !(a == b); }
bool operator !=(const String& a, const char* b) { return !(a == b); }
bool operator !=(const char* a, const String& b) { return !(a == b); }
bool operator !=(const String& string, char c) { return !(string == c); }
bool operator !=(char c, const String& string) { return !(string == c); }

std::ostream& operator <<(std::ostream& stream, const String& str)
{
	stream.write(str.getRawData(), str.length());
	return stream;
}

std::istream& operator >>(std::istream& stream, String& string)
{
	std::string s;
	stream >> s;

	string = String(s);

	return stream;
}

String::operator char* () const 
{
	// Create new C-style string
	char* buffer = new char[_length + 1];

	// Copy buffer and append zero termination
	std::memcpy(buffer, _buffer, _length);
	buffer[_length] = '\0';

	return buffer;
}

String::operator const char* () const { return static_cast<char*>(*this); }