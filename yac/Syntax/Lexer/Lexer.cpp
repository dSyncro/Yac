#include "Lexer.h"

#include <yac/Syntax/SyntaxRules.h>

using namespace Yac::Text;
using namespace Yac::Syntax;
using namespace Yac::Errors;

Lexer::Lexer(std::string source) : _source(source), _reporter(ErrorReporter()) {}

Token Lexer::Lex()
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

		case '+':
			_position++;
			_type = TokenType::PlusSymbol;
			return Token(_type, TextSpan(_start, 1), "+");

		case '-':
			_position++;
			_type = TokenType::MinusSymbol;
			return Token(_type, TextSpan(_start, 1), "-");

		case '*':
			_position++;
			_type = TokenType::StarSymbol;
			return Token(_type, TextSpan(_start, 1), "*");

		case '/':
			_position++;
			_type = TokenType::SlashSymbol;
			return Token(_type, TextSpan(_start, 1), "/");

		case '^':
			_position++;
			_type = TokenType::CircumflexSymbol;
			return Token(_type, TextSpan(_start, 1), "^");

		case '.':
			if (std::isdigit(Next()))
			{
				ReadNumber(TokenType::Double);
				break;
			}
			_position++;
			_type = TokenType::DotSymbol;
			return Token(_type, TextSpan(_start, 1), ".");

		case '=':
			_position++;
			_type = TokenType::EqualSymbol;
			return Token(_type, TextSpan(_start, 1), "=");

		case '&':
			_position++;
			_type = TokenType::AndSymbol;
			return Token(_type, TextSpan(_start, 1), "&");

		case '|':
			_position++;
			_type = TokenType::PipeSymbol;
			return Token(_type, TextSpan(_start, 1), "|");

		case '!':
			_position++;
			_type = TokenType::ExclamationMark;
			return Token(_type, TextSpan(_start, 1), "!");

		case '?':
			_position++;
			_type = TokenType::QuestionMark;
			return Token(_type, TextSpan(_start, 1), "?");

		case '<':
			_position++;
			_type = TokenType::LessSymbol;
			return Token(_type, TextSpan(_start, 1), "<");

		case '>':
			_position++;
			_type = TokenType::GreaterSymbol;
			return Token(_type, TextSpan(_start, 1), ">");

		case ':':
			_position++;
			_type = TokenType::Colon;
			return Token(_type, TextSpan(_start, 1), ":");

		case ';':
			_position++;
			_type = TokenType::Semicolon;
			return Token(_type, TextSpan(_start, 1), ";");

		case ',':
			_position++;
			_type = TokenType::Comma;
			return Token(_type, TextSpan(_start, 1), ",");

		case '(':
			_position++;
			_type = TokenType::OpenParentheses;
			return Token(_type, TextSpan(_start, 1), "(");

		case ')':
			_position++;
			_type = TokenType::CloseParentheses;
			return Token(_type, TextSpan(_start, 1), ")");

		case '[':
			_position++;
			_type = TokenType::OpenSquared;
			return Token(_type, TextSpan(_start, 1), "[");

		case ']':
			_position++;
			_type = TokenType::CloseParentheses;
			return Token(_type, TextSpan(_start, 1), "]");

		case '{':
			_position++;
			_type = TokenType::OpenBrackets;
			return Token(_type, TextSpan(_start, 1), "{");

		case '}':
			_position++;
			_type = TokenType::CloseBrackets;
			return Token(_type, TextSpan(_start, 1), "}");

		case '\n':
			_position++;
			_type = TokenType::Newline;
			return Token(_type, TextSpan(_start, 1), "\n");

		case '\0':
			_position++;
			_type = TokenType::EndOfFile;
			return Token(_type, TextSpan(_start, 1), "\0");

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

void Lexer::ReadWhitespace()
{
	_start = _position++;
	while (std::isspace(Current())) _position++;

	_type = TokenType::Whitespace;
}

void Lexer::ReadWord()
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

void Lexer::ReadNumber(TokenType startingType)
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

void Lexer::ReadBinaryNumber()
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

void Lexer::ReadHexNumber()
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

char Lexer::Peek(unsigned int offset) const noexcept
{
	unsigned int index = _position + offset;
	if (index > _source.length()) return '\0';
	return _source[index];
}