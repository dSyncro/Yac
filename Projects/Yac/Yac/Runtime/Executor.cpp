#include "Executor.h"

#include <Yac/API/Bool.h>
#include <Yac/API/Numerics.h>
#include <Yac/API/String.h>

#include <Yac/Core/Repl/VariableTable.h>

using namespace Yac;
using namespace Yac::Api;
using namespace Yac::Core;
using namespace Yac::Runtime;
using namespace Yac::Syntax;

int Executor::execute()
{
	evaluateStatement(_tree.getRoot());
	return 0;
}

void Executor::evaluateStatement(const Statement* statement)
{
	switch (statement->getType())
	{
		case StatementType::Block: return evaluateBlockStatement((BlockStatement*)statement);
		case StatementType::VariableDeclaration: return evaluateVariableDeclarationStatement((VariableDeclarationStatement*)statement);
		case StatementType::If: return evaluateIfStatement((IfStatement*)statement);
		case StatementType::For: return evaluateForStatement((ForStatement*)statement);
		case StatementType::While: return evaluateWhileStatement((WhileStatement*)statement);
		case StatementType::Expression: return evaluateExpressionStatement((ExpressionStatement*)statement);

		case StatementType::None:
		default: return;
	}
}

VariableData Executor::evaluateExpression(const Expression* expression)
{
	switch (expression->getType())
	{
		case ExpressionType::Identifier: return evaluateIdentifierExpression((IdentifierExpression*)expression);
		case ExpressionType::String: return evaluateStringExpression((StringExpression*)expression);
		case ExpressionType::Assignment: return evaluateAssignmentExpression((AssignmentExpression*)expression);
		case ExpressionType::Parentheses: return evaluateParethesesExpression((ParenthesesExpression*)expression);
		case ExpressionType::NumericLiteral: return evaluateNumericLiteralExpression((NumericLiteralExpression*)expression);
		case ExpressionType::BooleanLiteral: return evaluateBooleanLiteralExpression((BooleanLiteralExpression*)expression);
		case ExpressionType::UnaryOperation: return evaluateUnaryOperation((UnaryOperationExpression*)expression);
		case ExpressionType::BinaryOperation: return evaluateBinaryOperation((BinaryOperationExpression*)expression);
		case ExpressionType::ConditionalDeclaration: return evaluateConditionalDeclarationExpression((ConditionalDeclarationExpression*)expression);
		case ExpressionType::InlineIfElse: return evaluateInlineIfElseExpression((InlineIfElseExpression*)expression);

		case ExpressionType::None:
		default: return VariableData::null();
	}
}

// Statements

void Executor::evaluateBlockStatement(const BlockStatement* statement)
{
	_memory.stack.pushFrame();

	for (const Statement* s : statement->getStatements())
		evaluateStatement(s);

	_memory.stack.popFrame();
}

void Executor::evaluateVariableDeclarationStatement(const VariableDeclarationStatement* statement)
{
	const std::string& name = statement->getName();
	VariableData data = evaluateExpression(statement->getInitializer());
	_memory.stack.pushVariable(name, data);
}

void Executor::evaluateIfStatement(const IfStatement* statement)
{
	bool condition = _memory.getValue<bool>(evaluateExpression(statement->getCondition()));
	evaluateStatement(condition ? statement->getStatement() : statement->getElseStatement());
}

void Executor::evaluateForStatement(const ForStatement* statement)
{
	VariableData init = evaluateExpression(statement->getAssignment());
	VariableData condition = evaluateExpression(statement->getCondition());
	VariableData update = evaluateExpression(statement->getUpdate());

	while (_memory.getValue<bool>(condition))
	{
		evaluateStatement(statement->getStatement());
		evaluateExpression(statement->getUpdate());
		condition = evaluateExpression(statement->getCondition());
	}
}

void Executor::evaluateWhileStatement(const WhileStatement* statement)
{
	VariableData condition = evaluateExpression(statement->getCondition());

	while (_memory.getValue<bool>(condition))
	{
		evaluateStatement(statement->getStatement());
		condition = evaluateExpression(statement->getCondition());
	}
}

void Executor::evaluateExpressionStatement(const ExpressionStatement* statement)
{
	const Expression* expression = statement->getExpression();
	evaluateExpression(expression);
}

// Expressions

VariableData Executor::evaluateIdentifierExpression(const IdentifierExpression* expression)
{
	return _memory.stack.findVariable(expression->getIdentifier());
}

VariableData Executor::evaluateStringExpression(const StringExpression* expression)
{
	return VariableData(TypeSymbol::getStringTypeSymbol(), new String(expression->getText()));
}

VariableData Executor::evaluateAssignmentExpression(const AssignmentExpression* expression)
{
	const std::string& name = expression->getIdentifier();
	VariableData value = evaluateExpression(expression);
	_memory.stack.setVariable(name, value);
	return value;
}

VariableData Executor::evaluateParethesesExpression(const ParenthesesExpression* expression)
{
	return evaluateExpression(expression->getExpression());
}

VariableData Executor::evaluateNumericLiteralExpression(const NumericLiteralExpression* expression)
{
	switch (expression->getNumericType())
	{
		case NumericType::Int: 
		{
			IntT value = expression->toInt(); 
			return _memory.stack.pushValue(TypeSymbol::getIntTypeSymbol(), &value);
		}

		case NumericType::UInt: 
		{
			UIntT value = expression->toUInt(); 
			return _memory.stack.pushValue(TypeSymbol::getUIntTypeSymbol(), &value);
		}

		case NumericType::Float: 
		{
			float value = expression->toFloat();
			return _memory.stack.pushValue(TypeSymbol::getFloatTypeSymbol(), &value);
		}

		case NumericType::Double: 
		{
			double value = expression->toDouble();
			return _memory.stack.pushValue(TypeSymbol::getDoubleTypeSymbol(), &value);
		}

		default: return VariableData::null();
	}
}

VariableData Executor::evaluateBooleanLiteralExpression(const BooleanLiteralExpression* expression)
{
	return VariableData(TypeSymbol::getBoolTypeSymbol(), new Bool(expression->getValue()));
}

#include <Console.h>

VariableData Executor::evaluateUnaryOperation(const UnaryOperationExpression* expression)
{
	VariableData object = evaluateExpression(expression->getOperand());
	VariableData result = _memory.operatorTable.call(object.getType(), _memory.retrieve(object), expression->getOperation());
	Console::alert("Computed unary: ", _memory.getValue<int>(result));
	return result;
}

VariableData Executor::evaluateBinaryOperation(const BinaryOperationExpression* expression)
{
	VariableData left = evaluateExpression(expression->getLeft());
	VariableData right = evaluateExpression(expression->getRight());
	VariableData result = _memory.operatorTable.call(
		left.getType(), right.getType(), _memory.retrieve(left), _memory.retrieve(right), expression->getOperation()
	);
	Console::alert("Computed binary: ", _memory.getValue<int>(result));
	return result;
}

VariableData Executor::evaluateConditionalDeclarationExpression(const ConditionalDeclarationExpression* expression)
{
	return VariableData::null();
}

VariableData Executor::evaluateInlineIfElseExpression(const InlineIfElseExpression* expression)
{
	bool condition = _memory.getValue<bool>(evaluateExpression(expression->getCondition()));
	return condition ? evaluateExpression(expression->getTrueExpression()) : evaluateExpression(expression->getFalseExpression());
}