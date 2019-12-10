#include "NumericLiteral.h"

using namespace Yac::Syntax;

NumericLiteral::NumericLiteral(std::string text, NumericType type, NumericBase base)
	: Expression(ExpressionType::NumericLiteral), _text(text), _base(base), _numericType(type) {}