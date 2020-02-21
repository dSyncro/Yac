#include "Lexer.h"

#include <yac/Syntax/SyntaxRules.h>

using namespace Yac::Text;
using namespace Yac::Syntax;
using namespace Yac::Errors;

Lexer::Lexer(SourceText source, ErrorList& errorList) : _source(source), _reporter(errorList) {}

Token Lexer::Lex() noexcept
{
	_start = _position;
	_type = TokenType::Unknown;

	char c = Current();
	char next = Next();

	switch (c)
	{
		case '0':
			switch (next)
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

		case '"':
			ReadStringLiteral();
			break;

		case '+':
			return
				next == '+' ? ReadSymbol(TokenType::DoublePlusSymbol, "++", 2) :
				next == '=' ? ReadSymbol(TokenType::PlusEqualSymbol, "+=", 2) : ReadSymbol(TokenType::PlusSymbol, "+");

		case '-': 
			return
				next == '-' ? ReadSymbol(TokenType::DoubleMinusSymbol, "--", 2) :
				next == '=' ? ReadSymbol(TokenType::MinusEqualSymbol, "-=", 2) : ReadSymbol(TokenType::MinusSymbol, "-");

		case '*': 
			return next == '=' ? 
				ReadSymbol(TokenType::StarEqualSymbol, "*=", 2) : ReadSymbol(TokenType::StarSymbol, "*");

		case '/': 
			return next == '=' ?
				ReadSymbol(TokenType::SlashEqualSymbol, "/=", 2) : ReadSymbol(TokenType::SlashSymbol, "/");

		case '%':
			return next == '=' ?
				ReadSymbol(TokenType::PercentEqualSymbol, "%=", 2) : ReadSymbol(TokenType::PercentSymbol, "%");

		case '^': 
			return next == '=' ?
				ReadSymbol(TokenType::CircumflexEqualSymbol, "^=", 2) : ReadSymbol(TokenType::CircumflexSymbol, "^");

		case '.':
			if (std::isdigit(next))
			{
				ReadNumber(TokenType::Double);
				break;
			}
			return ReadSymbol(TokenType::DotSymbol, ".");

		case '=': 
			return next == '='  ? 
				ReadSymbol(TokenType::DoubleEqualSymbol, "==", 2) : ReadSymbol(TokenType::EqualSymbol, "=");

		case '&':
			return
				next == '&' ? ReadSymbol(TokenType::DoubleAndSymbol, "&&", 2) :
				next == '=' ? ReadSymbol(TokenType::AndEqualSymbol, "&=", 2) : ReadSymbol(TokenType::AndSymbol, "&");

		case '|':
			return
				next == '|' ? ReadSymbol(TokenType::DoublePipeSymbol, "||", 2) :
				next == '=' ? ReadSymbol(TokenType::PipeEqualSymbol, "|=", 2) : ReadSymbol(TokenType::PipeSymbol, "|");

		case '!':
			return next == '=' ?
				ReadSymbol(TokenType::NotEqualSymbol, "!=", 2) : ReadSymbol(TokenType::ExclamationMark, "!");

		case '~': return ReadSymbol(TokenType::TildeSymbol, "~");
		case '?': return ReadSymbol(TokenType::QuestionMark, "?");

		case '<':
			return
				next == '<' ?
				Peek(2) == '=' ? ReadSymbol(TokenType::SLEqualSymbol, "<<=", 3) : ReadSymbol(TokenType::ShiftLeftSymbol, "<<", 2) :
				next == '=' ? ReadSymbol(TokenType::LessEqualSymbol, "<=", 2) : ReadSymbol(TokenType::LessSymbol, "<");

		case '>':
			return
				next == '>' ?
				Peek(2) == '=' ? ReadSymbol(TokenType::SREqualSymbol, ">>=", 3) : ReadSymbol(TokenType::ShiftRightSymbol, ">>", 2) :
				next == '=' ? ReadSymbol(TokenType::GreaterEqualSymbol, ">=", 2) : ReadSymbol(TokenType::GreaterSymbol, ">");

		case ':': return ReadSymbol(TokenType::Colon, ":");
		case ';': return ReadSymbol(TokenType::Semicolon, ";");
		case ',': return ReadSymbol(TokenType::Comma, ",");
		case '(': return ReadSymbol(TokenType::OpenParentheses, "(");
		case ')': return ReadSymbol(TokenType::CloseParentheses, ")");
		case '[': return ReadSymbol(TokenType::OpenSquared, "[");
		case ']': return ReadSymbol(TokenType::CloseSquared, "]");
		case '{': return ReadSymbol(TokenType::OpenBrackets, "{");
		case '}': return ReadSymbol(TokenType::CloseBrackets, "}");

		case '\0': 
			if (_line < _source.lineCount())
			{
				Token t = ReadSymbol(TokenType::Newline, "\n");
				StepLine();
				return t;
			}
			else return ReadSymbol(TokenType::EndOfFile, "\0");

		default:
			if (std::isalpha(c) || c == '_') ReadWord();
			else
			{
				_reporter.ReportUnknownToken(c, TextSpan(_start, 1));
				_position++;
			}
			break;
	}

	unsigned int length = _position - _start;
	TextSpan span = TextSpan(_start, length);
	std::string text = CurrentLine().substr(span.start(), span.length());

	if (_type == TokenType::Word)
		_type = ToKeyword(text) == Keyword::Unknown ? TokenType::Identifier : TokenType::Keyword;
	
	return Token(_type, span, text, _line);
}

void Lexer::StepLine() noexcept
{
	_line++;
	_position = 0;
}

void Lexer::ReadWhitespace() noexcept
{
	_start = _position++;
	while (Current() == ' ' || Current() == '\t') _position++;

	_type = TokenType::Whitespace;
}

void Lexer::ReadWord() noexcept
{
	_start = _position++;
	bool isSurelyIdentifier = false;

	while (true)
	{
		char c = Current();

		if (!std::isalpha(c) && c != '_')
		{
			if (!std::isdigit(c)) break;
			isSurelyIdentifier = true;
		}

		if (std::isupper(c)) isSurelyIdentifier = true;

		_position++;
	}

	_type = isSurelyIdentifier ? TokenType::Identifier : TokenType::Word;
}

void Lexer::ReadStringLiteral() noexcept
{
	_start = _position++;
	while (Current() != '"') 
	{ 
		if (Current() == '\0')
		{
			std::size_t length = _position - _start;
			_reporter.ReportUnexpectedToken(TokenType::Quote, TokenType::EndOfFile, TextSpan(_start, length));
			return;
		}

		_position++; 
	}

	_position++; 
	_type = TokenType::StringLiteral;
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
	return Token(_type, TextSpan(_start, length), text, _line);
}

char Lexer::Peek(unsigned int offset) const noexcept
{
	unsigned int index = _position + offset;
	if (index > CurrentLine().length()) return '\0';
	return CurrentLine()[index];
}

const Line& Lexer::CurrentLine() const noexcept
{
	if (_line >= _source.lineCount()) return _source.GetLines().back();
	return _source[_line];
}