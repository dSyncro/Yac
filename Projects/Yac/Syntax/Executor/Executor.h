#pragma once

#include "NameTable.h"

#include <DataTypes/Operators/OperatorsTable.h>
#include <DataTypes/Variables/Data.h>
#include <DataTypes/Variables/Scope.h>

#include <Syntax/SyntaxTree/SyntaxTree.h>
#include <Syntax/Expressions/Expressions.h>
#include <Syntax/Statements/Statements.h>

namespace Yac::Syntax {

	class Executor {

	public:

		int Execute();

	private:

		void EvaluateStatement(const Statement* statement);
		Yac::DataTypes::Data EvaluateExpression(const Expression* expression);

		void EvaluateBlockStatement(const BlockStatement* statement);
		void EvaluateVariableDeclaration(const VariableDeclaration* statement);
		void EvaluateIfStatement(const IfStatement* statement);
		void EvaluateForStatement(const ForStatement* statement);
		void EvaluateWhileStatement(const WhileStatement* statement);
		void EvaluateExpressionStatement(const ExpressionStatement* statement);

		Yac::DataTypes::Data EvaluateIdentifierExpression(const IdentifierExpression* expression);
		Yac::DataTypes::Data EvaluateStringExpression(const StringExpression* expression);
		Yac::DataTypes::Data EvaluateAssignmentExpression(const AssignmentExpression* expression);
		Yac::DataTypes::Data EvaluateParethesesExpression(const ParenthesesExpression* expression);
		Yac::DataTypes::Data EvaluateNumericLiteral(const NumericLiteral* expression);
		Yac::DataTypes::Data EvaluateBooleanLiteral(const BooleanLiteral* expression);
		Yac::DataTypes::Data EvaluateUnaryOperation(const UnaryOperation* expression);
		Yac::DataTypes::Data EvaluateBinaryOperation(const BinaryOperation* expression);
		Yac::DataTypes::Data EvaluateConditionalDeclaration(const ConditionalDeclaration* expression);
		Yac::DataTypes::Data EvaluateInlineIfElse(const InlineIfElse* expression);

		Yac::DataTypes::Scope* _scope = new Yac::DataTypes::Scope();
		NameTable _nameTable = NameTable();

		Yac::DataTypes::OperatorsTable _operators = Yac::DataTypes::OperatorsTable();
	};
}