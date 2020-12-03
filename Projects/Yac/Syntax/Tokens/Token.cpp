#include "Token.h"

using namespace Yac::Syntax;
using namespace Yac::Text;

Token::Token() : Token(TokenType::None, { 0, 0 }, "", 0) { }

Token::Token(TokenType type, TextSpan span, const std::string& text, UInt line) 
	: _type(type), _span(span), _text(text), _line(line) {}