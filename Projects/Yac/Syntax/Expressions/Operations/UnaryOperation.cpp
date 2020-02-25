#include "UnaryOperation.h"

using namespace Yac::Syntax;

UnaryOperation::UnaryOperation(Operator operation, Expression* operand)
	: Expression(ExpressionType::UnaryOperation), _operation(operation), _operand(operand) {}

UnaryOperation::~UnaryOperation() { delete _operand; }