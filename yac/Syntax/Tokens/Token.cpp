#include "Token.h"

using namespace Yac::Syntax;
using namespace Yac::Text;

Token::Token() : _type(TokenType::None), _span({ 0, 0 }), _text("") { }

Token::Token(TokenType type, TextSpan span, std::string text) : _type(type), _span(span), _text(text) {}