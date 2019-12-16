#include "Lexer.h"

#include <yac/Syntax/SyntaxRules.h>

using namespace Yac::Text;
using namespace Yac::Syntax;
using namespace Yac::Errors;

Lexer::Lexer(std::string source) : _source(source), _reporter(ErrorReporter()) {}

Token Lexer::Lex() noexcept
{
	_start = _position;
	_type = TokenType::Unknown;

	char c = Current();

	switch (c)
	{
		case '0':
			switch (Next())
			{
				case 'b': 
					ReadBinaryNumber();
					break;
				case 'x': 
					ReadHexNumber();
					break;
				default:
					ReadNumber();
					break;
			}
			break;

		case '1': case '2': case '3': case '4':
		case '5': case '6': case '7': case '8': case '9':
			ReadNumber();
			break;

		case ' ': case '\t':
			ReadWhitespace();
			break;

		case '+': return ReadSymbol(TokenType::PlusSymbol, "+");
		case '-': return ReadSymbol(TokenType::MinusSymbol, "-");
		case '*': return ReadSymbol(TokenType::StarSymbol, "*");
		case '/': return ReadSymbol(TokenType::SlashSymbol, "/");
		case '^': return ReadSymbol(TokenType::CircumflexSymbol, "^");

		case '.':
			if (std::isdigit(Next()))
			{
				ReadNumber(TokenType::Double);
				break;
			}
			return ReadSymbol(TokenType::DotSymbol, ".");

		case '=': 
			return Next() == '='  ? 
				ReadSymbol(TokenType::EqualSymbol, "==", 2) : ReadSymbol(TokenType::EqualSymbol, "=");

		case '&':
			return Next() == '&' ?
				ReadSymbol(TokenType::AndSymbol, "&&", 2) : ReadSymbol(TokenType::AndSymbol, "&");

		case '|':
			return Next() == '|' ?
				ReadSymbol(TokenType::PipeSymbol, "||", 2) : ReadSymbol(TokenType::PipeSymbol, "|");

		case '!':
			return Next() == '=' ?
				ReadSymbol(TokenType::ExclamationMark, "!=", 2) : ReadSymbol(TokenType::ExclamationMark, "!");

		case '?': return ReadSymbol(TokenType::QuestionMark, "?");

		case '<':
			return Next() == '<' ?
				ReadSymbol(TokenType::LessSymbol, "<<", 2) : ReadSymbol(TokenType::LessSymbol, "<");

		case '>':
			return Next() == '>' ?
				ReadSymbol(TokenType::EqualSymbol, ">>", 2) : ReadSymbol(TokenType::GreaterSymbol, ">");

		case ':': return ReadSymbol(TokenType::Colon, ":");
		case ';': return ReadSymbol(TokenType::Semicolon, ";");
		case ',': return ReadSymbol(TokenType::Comma, ",");
		case '(': return ReadSymbol(TokenType::OpenParentheses, "(");
		case ')': return ReadSymbol(TokenType::CloseParentheses, ")");
		case '[': return ReadSymbol(TokenType::OpenSquared, "[");
		case ']': return ReadSymbol(TokenType::CloseSquared, "]");
		case '{': return ReadSymbol(TokenType::OpenBrackets, "{");
		case '}': return ReadSymbol(TokenType::CloseBrackets, "}");
		case '\n': return ReadSymbol(TokenType::Newline, "\n");
		case '\0': return ReadSymbol(TokenType::EndOfFile, "\0");

		default:
			if (std::isalpha(Current())) ReadWord();
			else
			{
				_reporter.ReportUnknownToken(c, TextSpan(_start, 1));
				_position++;
			}
			break;
	}

	unsigned int length = _position - _start;
	TextSpan span = TextSpan(_start, length);
	std::string text = _source.substr(span.start(), span.length());

	if (_type == TokenType::Word)
		_type = ToKeyword(text) == Keyword::Unknown ? TokenType::Identifier : TokenType::Keyword;
	
	return Token(_type, span, text);
}

void Lexer::ReadWhitespace() noexcept
{
	_start = _position++;
	while (std::isspace(Current())) _position++;

	_type = TokenType::Whitespace;
}

void Lexer::ReadWord() noexcept
{
	_start = _position++;
	bool isSurelyIdentifier = false;

	while (true)
	{
		char c = Current();

		if (!std::isalpha(c))
		{
			if (!std::isdigit(c)) break;
			isSurelyIdentifier = true;
		}

		if (std::isupper(c)) isSurelyIdentifier = true;

		_position++;
	}

	_type = isSurelyIdentifier ? TokenType::Identifier : TokenType::Word;
}

void Lexer::ReadNumber(TokenType startingType) noexcept
{
	_start = _position;
	_type = startingType;

	bool hasPower = false;

	// Magic happening here
	while (true)
	{
		_position++;

		char current = Current();

		bool isValid = std::isdigit(current) && 
			_type != TokenType::Float &&
			_type != TokenType::UInt;

		if (isValid) continue;

		switch (_type)
		{
			case TokenType::Int: {
				switch (current)
				{
					case '.':
						_type = TokenType::Double;
						continue;
					case 'f': case 'F':
						_type = TokenType::Float;
						continue;
					case 'u': case 'U':
						_type = TokenType::UInt;
						continue;
					case 'p': case 'P': case 'e': case 'E':
						_type = TokenType::Double;
						hasPower = true;
						continue;
					default: return;
				}
			}

			case TokenType::Double: {
				switch (current)
				{
					case 'f': case 'F':
						_type = TokenType::Float;
						continue;
					case 'p': case 'P': case 'e': case 'E':
						if (hasPower) return;
						hasPower = true;
						continue;
					default: return;
				}
			}

			default: return;
		}
	}
}

void Lexer::ReadBinaryNumber() noexcept
{
	_start = _position++;
	_type = TokenType::BinaryUInt;

	bool hasPower = false;

	// Magic happening here
	while (true)
	{
		_position++;

		char current = Current();
		bool isValid = (current == '0' ||
			current == '1' ||
			('2' <= current && current <= '9' && hasPower)) &&
			_type != TokenType::BinaryFloat;

		if (isValid) continue;

		switch (_type)
		{
			case TokenType::BinaryUInt: {
				switch (current)
				{
					case '.':
						_type = TokenType::BinaryDouble;
						continue;
					case 'f': case 'F':
						_type = TokenType::BinaryFloat;
						continue;
					case 'p': case 'P': case 'e': case 'E':
						_type = TokenType::BinaryDouble;
						hasPower = true;
						continue;
					default: return;
				}
			}

			case TokenType::BinaryDouble: {
				switch (current)
				{
					case 'f': case 'F':
						_type = TokenType::BinaryFloat;
						continue;
					case 'p': case 'P': case 'e': case 'E':
						if (hasPower) return;
						hasPower = true;
						continue;
					default: return;
				}
			}

			default: return;
		}
	}
}

void Lexer::ReadHexNumber() noexcept
{
	_start = _position++;
	_type = TokenType::HexUInt;

	bool hasPower = false;

	// Magic happening here
	while (true)
	{
		_position++;

		char current = Current();
		bool isValid = ('0' <= current && current <= '9' ||
			('a' <= current && current <= 'f' || 'A' <= current && current <= 'F') && !hasPower) &&
			_type != TokenType::HexFloat;

		if (isValid) continue;

		switch (_type)
		{
			case TokenType::HexUInt: {
				switch (current)
				{
					case '.':
						_type = TokenType::HexDouble;
						continue;
					case 'p': case 'P':
						_type = TokenType::HexDouble;
						hasPower = true;
						continue;
					default: return;
				}
			}

			case TokenType::BinaryDouble: {
				switch (current)
				{
					case 'f': case 'F':
						_type = TokenType::HexFloat;
						continue;
					case 'p': case 'P':
						if (hasPower) return;
						hasPower = true;
						continue;
					default: return;
				}
			}

			default: return;
		}
	}
}

Token Lexer::ReadSymbol(TokenType type, const char* text, unsigned int length) noexcept
{
	_position += length;
	_type = type;
	return Token(_type, TextSpan(_start, length), text);
}

char Lexer::Peek(unsigned int offset) const noexcept
{
	unsigned int index = _position + offset;
	if (index > _source.length()) return '\0';
	return _source[index];
}