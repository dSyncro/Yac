#include "Executor.h"

#include <API/Bool.h>
#include <API/Numerics.h>
#include <API/String.h>

#include <Core/Repl/VariableTable.h>

#include <DataTypes/Conversion.h>
#include <DataTypes/Types/StaticTypeSymbols.h>

using namespace Yac::Api;
using namespace Yac::Core;
using namespace Yac::DataTypes;
using namespace Yac::Syntax;

int Executor::Execute()
{
	return 0; //EvaluateStatement(_root);
}

void Executor::EvaluateStatement(const Statement* statement)
{
	switch (statement->type())
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

Data Executor::EvaluateExpression(const Expression* expression)
{
	switch (expression->type())
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
		default: return nullptr;
	}
}

// Statements

void Executor::EvaluateBlockStatement(const BlockStatement* statement)
{
	for (const Statement* s : statement->statements())
		EvaluateStatement(s);
}

void Executor::EvaluateVariableDeclaration(const VariableDeclaration* statement)
{
	std::string name = statement->name();
	EvaluateExpression(statement->initializer());
}

void Executor::EvaluateIfStatement(const IfStatement* statement)
{
	bool condition = EvaluateExpression(statement->condition()).value();
	EvaluateStatement(condition ? statement->statement() : statement->elseStatement());
}

void Executor::EvaluateForStatement(const ForStatement* statement)
{
	Data init = EvaluateExpression(statement->assignment());
	Data condition = EvaluateExpression(statement->condition());
	Data update = EvaluateExpression(statement->update());

	while ((bool)condition.value())
	{
		EvaluateStatement(statement->statement());
		EvaluateExpression(statement->update());
		condition = EvaluateExpression(statement->condition());
	}
}

void Executor::EvaluateWhileStatement(const WhileStatement* statement)
{
	Data condition = EvaluateExpression(statement->condition());

	while ((bool)condition.value())
	{
		EvaluateStatement(statement->statement());
		condition = EvaluateExpression(statement->condition());
	}
}

void Executor::EvaluateExpressionStatement(const ExpressionStatement* statement)
{
	const Expression* expression = statement->expression();
	EvaluateExpression(expression);
}

// Expressions

Data Executor::EvaluateIdentifierExpression(const IdentifierExpression* expression)
{
	return _scope->FindInHierarchy(expression->identifier());
}

Data Executor::EvaluateStringExpression(const StringExpression* expression)
{
	return Data(StringTypeSymbol, new String(expression->text()));
}

Data Executor::EvaluateAssignmentExpression(const AssignmentExpression* expression)
{
	std::string name;
	Data value = EvaluateExpression(expression);
	_scope->Set(name, value);
	return value;
}

Data Executor::EvaluateParethesesExpression(const ParenthesesExpression* expression)
{
	return EvaluateExpression(expression->expression());
}

Data Executor::EvaluateNumericLiteral(const NumericLiteral* expression)
{
	switch (expression->numeric_type())
	{
		case NumericType::Int: return Data(IntTypeSymbol, new Int(expression->ToInt()));
		case NumericType::UInt: return Data(UIntTypeSymbol, new UInt(expression->ToUInt()));
		case NumericType::Float: return Data(FloatTypeSymbol, new Float(expression->ToFloat()));
		case NumericType::Double: return Data(DoubleTypeSymbol, new Double(expression->ToDouble()));
		default: return nullptr;
	}
}

Data Executor::EvaluateBooleanLiteral(const BooleanLiteral* expression)
{
	return Data(BoolTypeSymbol, new Bool(expression->value()));
}

Data Executor::EvaluateUnaryOperation(const UnaryOperation* expression)
{
	Data object = EvaluateExpression(expression->operand());
	switch (expression->operation())
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

Data Executor::EvaluateBinaryOperation(const BinaryOperation* expression)
{
	return nullptr;
}

Data Executor::EvaluateConditionalDeclaration(const ConditionalDeclaration* expression)
{
	return nullptr;
}

Data Executor::EvaluateInlineIfElse(const InlineIfElse* expression)
{
	Bool condition = EvaluateExpression(expression->condition()).value();
	return condition ? EvaluateExpression(expression->True()) : EvaluateExpression(expression->False());
}