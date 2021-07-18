#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "UInt.h"

namespace Yac::Api {

	struct IStringable
	{
		virtual void ToString() = 0;
	};

	class String;

	using StringList = std::vector<String>;

	class String
	{

	public:

		/**
		 * @brief Construct an empty string.
		*/
		String();

		/**
		 * @brief Construct string from a single char.
		 * @param c The char.
		*/
		String(char c);

		/**
		 * @brief Construct string from repeating char.
		 * @param c The char.
		 * @param amount The amount of times the char is repeated.
		*/
		String(char c, UInt amount);

		/**
		 * @brief Construct string from C-style string.
		 * @param string C-style string.
		*/
		String(const char* string);

		/**
		 * @brief Construct string from C++ standard string.
		 * @param string C++ std::string.
		*/
		String(const std::string& string);

		/**
		 * @brief Copy a string.
		 * @param string The string to copy.
		*/
		String(const String& string);

		/**
		 * @brief Dispose string.
		*/
		~String();

		/**
		 * @brief Count char occurrencies.
		 * @param c The char.
		 * @return The occurrencies of `c` in this string.
		*/
		UInt count(char c) const noexcept;

		/**
		 * @brief Count occurrencies of substring.
		 * @param substring The substring.
		 * @return The occurrencies of `substring` in this string.
		*/
		UInt count(const String& substring) const noexcept;

		/**
		 * @brief Get first index of char.
		 * @param c The char.
		 * @return First index of `c`. returns UInt::infinity() if not found.
		*/
		UInt firstIndexOf(char c) const noexcept;

		/**
		 * @brief Get first index of substring.
		 * @param substring The substring.
		 * @return First index of `substring`. returns UInt::infinity() if not found.
		*/
		UInt firstIndexOf(const String& substring) const noexcept;

		/**
		 * @brief Get last index of char.
		 * @param c The char.
		 * @return Last index of `c`. returns UInt::infinity() if not found.
		*/
		UInt lastIndexOf(char c) const noexcept;

		/**
		 * @brief Get last index of substring.
		 * @param substring The substring.
		 * @return Last index of `substring`. returns UInt::infinity() if not found.
		*/
		UInt lastIndexOf(const String& substring) const noexcept;

		/**
		 * @brief Get string length.
		 * @return String length.
		*/
		UInt length() const noexcept { return _length; }

		/**
		 * @brief Check if string contains char.
		 * @param c The char.
		*/
		bool contains(char c) const noexcept;

		/**
		 * @brief Check if string contains substring.
		 * @param substring The substring.
		*/
		bool contains(const String& substring) const noexcept;

		/**
		 * @brief Check if string only contains alphabet letters.
		*/
		bool isAlphabet() const noexcept;

		/**
		 * @brief Check if string only constains alphanumeric chars.
		*/
		bool isAlphanum() const noexcept;

		/**
		 * @brief Check if string is empty.
		*/
		bool isEmpty() const noexcept { return _length == 0; }

		/**
		 * @brief Check if string only contains lowercase chars.
		*/
		bool isLower() const noexcept;

		/**
		 * @brief Check if string only contains uppercase chars.
		*/
		bool isUpper() const noexcept;

		/**
		 * @brief Check if string only contains digits.
		*/
		bool isNumber() const noexcept;

		/**
		 * @brief Get a pointer to underlying char buffer.
		*/
		const char* getRawData() const noexcept { return _buffer; }

		/**
		 * @brief Get substring from string.
		 * @param start Starting position of the substring in this string instance.
		 * @param length Substring length.
		 * @return Substring from `start` to `start` + `length`.
		*/
		String substring(UInt start, UInt length) const;

		/**
		 * @brief Remove whitespaces from both ends of the string.
		 * @return A string without starting and ending whitespaces.
		*/
		String strip() const noexcept;

		/**
		 * @brief Remove specified char from both ends of the string.
		 * @param c The char.
		 * @return A string without starting and ending `c`.
		*/
		String strip(char c) const noexcept;

		/**
		 * @brief Remove whitespaces from beginning of the string.
		 * @return A string without starting whitespaces.
		*/
		String lStrip() const noexcept;

		/**
		 * @brief Remove specified char from beginning of the string.
		 * @param c The char.
		 * @return A string without starting `c`.
		*/
		String lStrip(char c) const noexcept;

		/**
		 * @brief Remove whitespaces from ending of the string.
		 * @return A string without ending whitespaces.
		*/
		String rStrip() const noexcept;

		/**
		 * @brief Remove specified char from ending of the string.
		 * @param c The char.
		 * @return A string without ending `c`.
		*/
		String rStrip(char c) const noexcept;

		/**
		 * @brief Remove specified char from string.
		 * @param c The char.
		 * @return A string specified char.
		*/
		String remove(char c) const noexcept;

		/**
		 * @brief Remove char at index.
		 * @param index The index.
		 * @return A string without specified char.
		*/
		String removeAt(UInt index) const;

		/**
		 * @brief Remove first occurrence of specified char.
		 * @param c The char.
		 * @return A string without first occurrence of specified char.
		*/
		String removeFirst(char c) const noexcept;

		/**
		 * @brief Remove last occurrence of specified char.
		 * @param c The char.
		 * @return A string without last occurrence of specified char.
		*/
		String removeLast(char c) const noexcept;

		/**
		 * @brief Replace char at index.
		 * @param index The index.
		 * @param c New char.
		 * @return A string with char at index replaced with `c`.
		*/
		String replaceAt(UInt index, char c) const;

		/**
		 * @brief Replace first occurrence of specified char.
		 * @param before Old char.
		 * @param after New char.
		 * @return A string with first occurrence of `before` replaced with `after`.
		*/
		String replaceFirst(char before, char after) const noexcept;

		/**
		 * @brief Replace last occurrence of specified char.
		 * @param before Old char.
		 * @param after New char.
		 * @return A string with last occurrence of `before` replaced with `after`.
		*/
		String replaceLast(char before, char after) const noexcept;

		/**
		 * @brief Replace specified char.
		 * @param before Old char.
		 * @param after New char.
		 * @return A string with `before` replaced with `after`.
		*/
		String replaceAll(char before, char after) const noexcept;

		/**
		 * @brief Get a lowercase version of this string.
		 * @return A string with only lowercase chars.
		*/
		String toLower() const noexcept;

		/**
		 * @brief Get an uppercase version of this string.
		 * @return A string with only uppercase chars.
		*/
		String toUpper() const noexcept;

		/**
		 * @brief Toggle case for each chars in this string.
		 * @return A string with toggle-cased chars compared to this instance.
		*/
		String toggleCase() const noexcept;

		/**
		 * @brief Split string using a separator char.
		 * @param c The separator.
		 * @return A string list containing each separated string.
		*/
		StringList split(char c) const;

		/**
		 * @brief An empty string.
		 * @return Empty string.
		*/
		static const String& empty() noexcept;

		char operator[](UInt index) const { return _buffer[index]; }
		char& operator[](UInt index) { return _buffer[index]; }

		String& operator =(const String& string);
		String& operator +=(const String& string);
		String& operator *=(UInt n);

		friend String operator *(const String& string, UInt n);

		explicit operator char* () const;
		explicit operator const char* () const;

	private:

		char* _buffer;
		UInt _length;

		String(char* chars, UInt length); // potentially dangerous constructor, meant for internal use
	};
}

String operator +(const String& a, const String& b);
String operator +(const String& string, char c);
String operator +(const String& string, const char* other);
String operator +(char a, const String& b);
String operator +(const char* a, const String& b);

String operator *(UInt n, const String& string);

bool operator ==(const String& a, const String& b);
bool operator ==(const String& a, const char* b);
bool operator ==(const char* a, const String& b);
bool operator ==(const String& str, char c);
bool operator ==(char c, const String& string);

bool operator !=(const String& a, const String& b);
bool operator !=(const String& a, const char* b);
bool operator !=(const char* a, const String& b);
bool operator !=(const String& str, char c);
bool operator !=(char c, const String& str);

std::ostream& operator <<(std::ostream& stream, const String& string);
std::istream& operator >>(std::istream& stream, String& string);