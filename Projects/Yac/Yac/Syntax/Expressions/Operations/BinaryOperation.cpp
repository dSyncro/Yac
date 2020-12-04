#include "BinaryOperation.h"

using namespace Yac::Syntax;

BinaryOperation::BinaryOperation(Expression* left, Operator operation, Expression* right)
	: Expression(ExpressionType::BinaryOperation), _left(left), _operation(operation), _right(right) {}

BinaryOperation::~BinaryOperation() 
{
	delete _left;
	delete _right;
}