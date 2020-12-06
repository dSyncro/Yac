#include "Executor.h"

#include <Yac/API/Bool.h>
#include <Yac/API/Numerics.h>
#include <Yac/API/String.h>

#include <Yac/Core/Repl/VariableTable.h>

using namespace Yac::Api;
using namespace Yac::Core;
using namespace Yac::Runtime;
using namespace Yac::Syntax;

int Executor::Execute()
{
	return 0; //EvaluateStatement(_root);
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
		default: return VariableData();
	}
}

// Statements

void Executor::evaluateBlockStatement(const BlockStatement* statement)
{
	for (const Statement* s : statement->getStatements())
		evaluateStatement(s);
}

void Executor::evaluateVariableDeclarationStatement(const VariableDeclarationStatement* statement)
{
	std::string name = statement->getName();
	evaluateExpression(statement->getInitializer());
}

void Executor::evaluateIfStatement(const IfStatement* statement)
{
	bool condition = evaluateExpression(statement->getCondition()).getValue();
	evaluateStatement(condition ? statement->getStatement() : statement->getElseStatement());
}

void Executor::evaluateForStatement(const ForStatement* statement)
{
	VariableData init = evaluateExpression(statement->getAssignment());
	VariableData condition = evaluateExpression(statement->getCondition());
	VariableData update = evaluateExpression(statement->getUpdate());

	while ((bool)condition.getValue())
	{
		evaluateStatement(statement->getStatement());
		evaluateExpression(statement->getUpdate());
		condition = evaluateExpression(statement->getCondition());
	}
}

void Executor::evaluateWhileStatement(const WhileStatement* statement)
{
	VariableData condition = evaluateExpression(statement->getCondition());

	while ((bool)condition.getValue())
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
	return _scope->findInHierarchy(expression->getIdentifier());
}

VariableData Executor::evaluateStringExpression(const StringExpression* expression)
{
	return VariableData(getStringTypeSymbol(), new String(expression->getText()));
}

VariableData Executor::evaluateAssignmentExpression(const AssignmentExpression* expression)
{
	std::string name;
	VariableData value = evaluateExpression(expression);
	_scope->set(name, value);
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
		case NumericType::Int: return VariableData(getIntTypeSymbol(), new Int(expression->toInt()));
		case NumericType::UInt: return VariableData(getUIntTypeSymbol(), new UInt(expression->toUInt()));
		case NumericType::Float: return VariableData(getFloatTypeSymbol(), new Float(expression->toFloat()));
		case NumericType::Double: return VariableData(getDoubleTypeSymbol(), new Double(expression->toDouble()));
		default: return VariableData();
	}
}

VariableData Executor::evaluateBooleanLiteralExpression(const BooleanLiteralExpression* expression)
{
	return VariableData(getBoolTypeSymbol(), new Bool(expression->getValue()));
}

VariableData Executor::evaluateUnaryOperation(const UnaryOperationExpression* expression)
{
	VariableData object = evaluateExpression(expression->getOperand());
	switch (expression->getOperation())
	{
		case Operator::Identity:
			//UnaryOperatorOverload overload = UnaryOperatorOverload(Operator::Identity, object.type(), object.type());
			//_operators.Call(overload, object.value(), *data);
			return object;
		case Operator::Negation:
			return object;
		case Operator::PreIncrement:
			return object;
		case Operator::PreDecrement:
			return object;
		case Operator::LogicalNot:
			return object;
		case Operator::OneComplementary:
			return object;
		case Operator::PostIncrement:
			return object;
		case Operator::PostDecrement:
			return object;
		default: return object;
	}
}

VariableData Executor::evaluateBinaryOperation(const BinaryOperationExpression* expression)
{
	return VariableData();
}

VariableData Executor::evaluateConditionalDeclarationExpression(const ConditionalDeclarationExpression* expression)
{
	return VariableData();
}

VariableData Executor::evaluateInlineIfElseExpression(const InlineIfElseExpression* expression)
{
	Bool condition = evaluateExpression(expression->getCondition()).getValue();
	return condition ? evaluateExpression(expression->getTrueExpression()) : evaluateExpression(expression->getFalseExpression());
}