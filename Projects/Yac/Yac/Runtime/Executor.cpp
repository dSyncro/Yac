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

void Executor::EvaluateStatement(const Statement* statement)
{
	switch (statement->getType())
	{
		case StatementType::Block: return EvaluateBlockStatement((BlockStatement*)statement);
		case StatementType::VariableDeclaration: return EvaluateVariableDeclaration((VariableDeclaration*)statement);
		case StatementType::If: return EvaluateIfStatement((IfStatement*)statement);
		case StatementType::For: return EvaluateForStatement((ForStatement*)statement);
		case StatementType::While: return EvaluateWhileStatement((WhileStatement*)statement);
		case StatementType::Expression: return EvaluateExpressionStatement((ExpressionStatement*)statement);

		case StatementType::None:
		default: return;
	}
}

TypedData Executor::EvaluateExpression(const Expression* expression)
{
	switch (expression->getType())
	{
		case ExpressionType::IdentifierExpression: return EvaluateIdentifierExpression((IdentifierExpression*)expression);
		case ExpressionType::StringExpression: return EvaluateStringExpression((StringExpression*)expression);
		case ExpressionType::AssignmentExpression: return EvaluateAssignmentExpression((AssignmentExpression*)expression);
		case ExpressionType::ParenthesesExpression: return EvaluateParethesesExpression((ParenthesesExpression*)expression);
		case ExpressionType::NumericLiteral: return EvaluateNumericLiteral((NumericLiteral*)expression);
		case ExpressionType::BooleanLiteral: return EvaluateBooleanLiteral((BooleanLiteral*)expression);
		case ExpressionType::UnaryOperation: return EvaluateUnaryOperation((UnaryOperation*)expression);
		case ExpressionType::BinaryOperation: return EvaluateBinaryOperation((BinaryOperation*)expression);
		case ExpressionType::ConditionalDeclaration: return EvaluateConditionalDeclaration((ConditionalDeclaration*)expression);
		case ExpressionType::InlineIfElse: return EvaluateInlineIfElse((InlineIfElse*)expression);

		case ExpressionType::None:
		default: return TypedData();
	}
}

// Statements

void Executor::EvaluateBlockStatement(const BlockStatement* statement)
{
	for (const Statement* s : statement->getStatements())
		EvaluateStatement(s);
}

void Executor::EvaluateVariableDeclaration(const VariableDeclaration* statement)
{
	std::string name = statement->getName();
	EvaluateExpression(statement->getInitializer());
}

void Executor::EvaluateIfStatement(const IfStatement* statement)
{
	bool condition = EvaluateExpression(statement->getCondition()).getValue();
	EvaluateStatement(condition ? statement->getStatement() : statement->getElseStatement());
}

void Executor::EvaluateForStatement(const ForStatement* statement)
{
	TypedData init = EvaluateExpression(statement->getAssignment());
	TypedData condition = EvaluateExpression(statement->getCondition());
	TypedData update = EvaluateExpression(statement->getUpdate());

	while ((bool)condition.getValue())
	{
		EvaluateStatement(statement->getStatement());
		EvaluateExpression(statement->getUpdate());
		condition = EvaluateExpression(statement->getCondition());
	}
}

void Executor::EvaluateWhileStatement(const WhileStatement* statement)
{
	TypedData condition = EvaluateExpression(statement->getCondition());

	while ((bool)condition.getValue())
	{
		EvaluateStatement(statement->getStatement());
		condition = EvaluateExpression(statement->getCondition());
	}
}

void Executor::EvaluateExpressionStatement(const ExpressionStatement* statement)
{
	const Expression* expression = statement->getExpression();
	EvaluateExpression(expression);
}

// Expressions

TypedData Executor::EvaluateIdentifierExpression(const IdentifierExpression* expression)
{
	return _scope->findInHierarchy(expression->getIdentifier());
}

TypedData Executor::EvaluateStringExpression(const StringExpression* expression)
{
	return TypedData(getStringTypeSymbol(), new String(expression->getText()));
}

TypedData Executor::EvaluateAssignmentExpression(const AssignmentExpression* expression)
{
	std::string name;
	TypedData value = EvaluateExpression(expression);
	_scope->set(name, value);
	return value;
}

TypedData Executor::EvaluateParethesesExpression(const ParenthesesExpression* expression)
{
	return EvaluateExpression(expression->getExpression());
}

TypedData Executor::EvaluateNumericLiteral(const NumericLiteral* expression)
{
	switch (expression->getNumericType())
	{
		case NumericType::Int: return TypedData(getIntTypeSymbol(), new Int(expression->toInt()));
		case NumericType::UInt: return TypedData(getUIntTypeSymbol(), new UInt(expression->toUInt()));
		case NumericType::Float: return TypedData(getFloatTypeSymbol(), new Float(expression->toFloat()));
		case NumericType::Double: return TypedData(getDoubleTypeSymbol(), new Double(expression->toDouble()));
		default: return TypedData();
	}
}

TypedData Executor::EvaluateBooleanLiteral(const BooleanLiteral* expression)
{
	return TypedData(getBoolTypeSymbol(), new Bool(expression->getValue()));
}

TypedData Executor::EvaluateUnaryOperation(const UnaryOperation* expression)
{
	TypedData object = EvaluateExpression(expression->getOperand());
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

TypedData Executor::EvaluateBinaryOperation(const BinaryOperation* expression)
{
	return TypedData();
}

TypedData Executor::EvaluateConditionalDeclaration(const ConditionalDeclaration* expression)
{
	return TypedData();
}

TypedData Executor::EvaluateInlineIfElse(const InlineIfElse* expression)
{
	Bool condition = EvaluateExpression(expression->getCondition()).getValue();
	return condition ? EvaluateExpression(expression->getTrueExpression()) : EvaluateExpression(expression->getFalseExpression());
}