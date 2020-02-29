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
using namespace Yac::Syntax::Binding;

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

BoundObject* Executor::EvaluateExpression(const Expression* expression)
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
	bool condition = EvaluateExpression(statement->condition());
	EvaluateStatement(condition ? statement->statement() : statement->elseStatement());
}

void Executor::EvaluateForStatement(const ForStatement* statement)
{
	BoundObject* init = EvaluateExpression(statement->assignment());
	BoundObject* condition = EvaluateExpression(statement->condition());
	BoundObject* update = EvaluateExpression(statement->update());

	while (condition)
	{
		EvaluateStatement(statement->statement());
		EvaluateExpression(statement->update());
		condition = EvaluateExpression(statement->condition());
	}
}

void Executor::EvaluateWhileStatement(const WhileStatement* statement)
{
	BoundObject* condition = EvaluateExpression(statement->condition());

	while (condition)
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

BoundObject* Executor::EvaluateIdentifierExpression(const IdentifierExpression* expression)
{
	return _scope->FindInHierarchy(expression->identifier());
}

BoundObject* Executor::EvaluateStringExpression(const StringExpression* expression)
{
	return new BoundObject(StringTypeSymbol, new String(expression->text()));
}

BoundObject* Executor::EvaluateAssignmentExpression(const AssignmentExpression* expression)
{
	std::string name;
	BoundObject* value = EvaluateExpression(expression);
	_scope->Set(name, value);
	return nullptr;
}

BoundObject* Executor::EvaluateParethesesExpression(const ParenthesesExpression* expression)
{
	return EvaluateExpression(expression->expression());
}

BoundObject* Executor::EvaluateNumericLiteral(const NumericLiteral* expression)
{
	switch (expression->numeric_type())
	{
		case NumericType::Int: return new BoundObject(IntTypeSymbol, new Int(expression->ToInt()));
		case NumericType::UInt: return new BoundObject(UIntTypeSymbol, new UInt(expression->ToUInt()));
		case NumericType::Float: return new BoundObject(FloatTypeSymbol, new Float(expression->ToFloat()));
		case NumericType::Double: return new BoundObject(DoubleTypeSymbol, new Double(expression->ToDouble()));
		default: return nullptr;
	}
}

BoundObject* Executor::EvaluateBooleanLiteral(const BooleanLiteral* expression)
{
	return new BoundObject(BoolTypeSymbol, new Bool(expression->value()));
}

BoundObject* Executor::EvaluateUnaryOperation(const UnaryOperation* expression)
{
	return nullptr;
}

BoundObject* Executor::EvaluateBinaryOperation(const BinaryOperation* expression)
{
	return nullptr;
}

BoundObject* Executor::EvaluateConditionalDeclaration(const ConditionalDeclaration* expression)
{
	return nullptr;
}

BoundObject* Executor::EvaluateInlineIfElse(const InlineIfElse* expression)
{
	Bool condition = EvaluateExpression(expression->condition())->Reference();
	return condition ? EvaluateExpression(expression->True()) : EvaluateExpression(expression->False());
}

void Executor::PushScope() noexcept
{
	_scope = new Scope(*_scope);
}

void Executor::PopScope() noexcept
{
	Scope* parent = _scope->Parent();

	delete _scope;

	_scope = parent ? parent : new Scope();
}