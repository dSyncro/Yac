#include "Lexer.h"

#include <Yac/Syntax/SyntaxRules.h>

using namespace Yac::Errors;
using namespace Yac::Syntax;
using namespace Yac::Text;

Lexer::Lexer(const SourceText& source, ErrorList& errorList) : _source(source), _errorList(errorList) {}

Token Lexer::consumeNext() noexcept
{
	_start = _position;
	_type = TokenType::Unknown;

	char current = getCurrent();
	char next = getNext();

	switch (current)
	{
		case '0':
			switch (next)
			{
				case 'b': 
					readBinaryNumber();
					break;
				case 'x': 
					readHexNumber();
					break;
			}
			[[fallthrough]];
		case '1': case '2': case '3': case '4':
		case '5': case '6': case '7': case '8': case '9':
			readNumber();
			break;

		case ' ': case '\t':
			readWhitespace();
			break;

		case '"':
			readStringLiteral();
			break;

		case '+':
			return
				next == '+' ? produceSymbol(TokenType::DoublePlusSymbol, "++", 2) :
				next == '=' ? produceSymbol(TokenType::PlusEqualSymbol, "+=", 2) : produceSymbol(TokenType::PlusSymbol, "+");

		case '-': 
			return
				next == '-' ? produceSymbol(TokenType::DoubleMinusSymbol, "--", 2) :
				next == '=' ? produceSymbol(TokenType::MinusEqualSymbol, "-=", 2) : produceSymbol(TokenType::MinusSymbol, "-");

		case '*': 
			return next == '=' ? 
				produceSymbol(TokenType::StarEqualSymbol, "*=", 2) : produceSymbol(TokenType::StarSymbol, "*");

		case '/': 
			return next == '=' ?
				produceSymbol(TokenType::SlashEqualSymbol, "/=", 2) : produceSymbol(TokenType::SlashSymbol, "/");

		case '%':
			return next == '=' ?
				produceSymbol(TokenType::PercentEqualSymbol, "%=", 2) : produceSymbol(TokenType::PercentSymbol, "%");

		case '^': 
			return next == '=' ?
				produceSymbol(TokenType::CircumflexEqualSymbol, "^=", 2) : produceSymbol(TokenType::CircumflexSymbol, "^");

		case '.':
			if (std::isdigit(next))
			{
				readNumber(TokenType::Double);
				break;
			}
			return produceSymbol(TokenType::DotSymbol, ".");

		case '=': 
			return next == '='  ? 
				produceSymbol(TokenType::DoubleEqualSymbol, "==", 2) : produceSymbol(TokenType::EqualSymbol, "=");

		case '&':
			return
				next == '&' ? produceSymbol(TokenType::DoubleAndSymbol, "&&", 2) :
				next == '=' ? produceSymbol(TokenType::AndEqualSymbol, "&=", 2) : produceSymbol(TokenType::AndSymbol, "&");

		case '|':
			return
				next == '|' ? produceSymbol(TokenType::DoublePipeSymbol, "||", 2) :
				next == '=' ? produceSymbol(TokenType::PipeEqualSymbol, "|=", 2) : produceSymbol(TokenType::PipeSymbol, "|");

		case '!':
			return next == '=' ?
				produceSymbol(TokenType::NotEqualSymbol, "!=", 2) : produceSymbol(TokenType::ExclamationMark, "!");

		case '~': return produceSymbol(TokenType::TildeSymbol, "~");
		case '?': return produceSymbol(TokenType::QuestionMark, "?");

		case '<':
			return
				next == '<' ?
				peek(2) == '=' ? produceSymbol(TokenType::SLEqualSymbol, "<<=", 3) : produceSymbol(TokenType::ShiftLeftSymbol, "<<", 2) :
				next == '=' ? produceSymbol(TokenType::LessEqualSymbol, "<=", 2) : produceSymbol(TokenType::LessSymbol, "<");

		case '>':
			return
				next == '>' ?
				peek(2) == '=' ? produceSymbol(TokenType::SREqualSymbol, ">>=", 3) : produceSymbol(TokenType::ShiftRightSymbol, ">>", 2) :
				next == '=' ? produceSymbol(TokenType::GreaterEqualSymbol, ">=", 2) : produceSymbol(TokenType::GreaterSymbol, ">");

		case ':': return produceSymbol(TokenType::Colon, ":");
		case ';': return produceSymbol(TokenType::Semicolon, ";");
		case ',': return produceSymbol(TokenType::Comma, ",");
		case '(': return produceSymbol(TokenType::OpenParentheses, "(");
		case ')': return produceSymbol(TokenType::CloseParentheses, ")");
		case '[': return produceSymbol(TokenType::OpenSquared, "[");
		case ']': return produceSymbol(TokenType::CloseSquared, "]");
		case '{': return produceSymbol(TokenType::OpenBrackets, "{");
		case '}': return produceSymbol(TokenType::CloseBrackets, "}");

		case '\0': 
			if (_line < _source.getLineCount() - 1)
			{
				Token t = produceSymbol(TokenType::Newline, "\n");
				stepLine();
				return t;
			}
			else return produceSymbol(TokenType::EndOfFile, "\0");

		default:
			if (std::isalpha(current) || current == '_') return produceWord();
			else
			{
				_errorList.reportUnknownToken(current, TextSpan(_start, 1));
				_position++;
			}
			break;
	}

	UIntT length = _position - _start;
	TextSpan span = TextSpan(_start, length);
	std::string text = getCurrentLine().getSubstring(span.getStart(), span.getLength());
	
	return Token(_type, span, text, _line);
}

void Lexer::stepLine() noexcept
{
	_line++;
	_position = 0;
}

void Lexer::readWhitespace() noexcept
{
	_start = _position++;
	while (getCurrent() == ' ' || getCurrent() == '\t') _position++;

	_type = TokenType::Whitespace;
}

Token Lexer::produceWord() noexcept
{
	_start = _position++;
	bool isSurelyIdentifier = false;

	while (true)
	{
		char c = getCurrent();

		if (!std::isalpha(c) && c != '_')
		{
			if (!std::isdigit(c)) break;
			isSurelyIdentifier = true;
		}

		if (std::isupper(c)) isSurelyIdentifier = true;

		_position++;
	}

	UIntT length = _position - _start;
	TextSpan span = TextSpan(_start, length);

	_text = getCurrentLine().getSubstring(span.getStart(), span.getLength());

	if (isSurelyIdentifier)
	{
		_type = TokenType::Identifier;
		return Token(_type, span, _text, _line);
	}
	
	_type = toKeyword(_text) != Keyword::Unknown ? TokenType::Keyword : TokenType::Identifier;

	return Token(_type, span, _text, _line);
}

void Lexer::readStringLiteral() noexcept
{
	_start = _position++;
	while (getCurrent() != '"') 
	{ 
		if (getCurrent() == '\0')
		{
			std::size_t length = _position - _start;
			_errorList.reportUnexpectedToken(TokenType::Quote, TokenType::EndOfFile, TextSpan(_start, length));
			return;
		}

		_position++; 
	}

	_position++; 
	_type = TokenType::StringLiteral;
}

void Lexer::readNumber(TokenType startingType) noexcept
{
	_start = _position;
	_type = startingType;

	bool hasPower = false;

	// Magic happening here
	while (true)
	{
		_position++;

		char current = getCurrent();

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

void Lexer::readBinaryNumber() noexcept
{
	_start = _position++;
	_type = TokenType::BinaryUInt;

	bool hasPower = false;

	// Magic happening here
	while (true)
	{
		_position++;

		char current = getCurrent();
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

void Lexer::readHexNumber() noexcept
{
	_start = _position++;
	_type = TokenType::HexUInt;

	bool hasPower = false;

	// Magic happening here
	while (true)
	{
		_position++;

		char current = getCurrent();
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

Token Lexer::produceSymbol(TokenType type, const char* text, UIntT length) noexcept
{
	_position += length;
	_type = type;
	return Token(_type, TextSpan(_start, length), text, _line);
}

char Lexer::peek(UIntT offset) const noexcept
{
	UIntT index = _position + offset;
	if (index > getCurrentLine().getLength()) return '\0';
	return getCurrentLine()[index];
}

const Line& Lexer::getCurrentLine() const noexcept
{
	if (_line >= _source.getLineCount()) return _source.getLines().back();
	return _source[_line];
}