#pragma once

#include "NameTable.h"

#include <Yac/DataTypes/Operators/OperatorsTable.h>
#include <Yac/DataTypes/Variables/Data.h>
#include <Yac/DataTypes/Variables/Scope.h>

#include <Yac/Syntax/SyntaxTree/SyntaxTree.h>
#include <Yac/Syntax/Expressions/Expressions.h>
#include <Yac/Syntax/Statements/Statements.h>

namespace Yac::Syntax {

	class Executor {

	public:

		int Execute();

	private:

		void EvaluateStatement(const Statement* statement);
		DataTypes::Data EvaluateExpression(const Expression* expression);

		void EvaluateBlockStatement(const BlockStatement* statement);
		void EvaluateVariableDeclaration(const VariableDeclaration* statement);
		void EvaluateIfStatement(const IfStatement* statement);
		void EvaluateForStatement(const ForStatement* statement);
		void EvaluateWhileStatement(const WhileStatement* statement);
		void EvaluateExpressionStatement(const ExpressionStatement* statement);

		DataTypes::Data EvaluateIdentifierExpression(const IdentifierExpression* expression);
		DataTypes::Data EvaluateStringExpression(const StringExpression* expression);
		DataTypes::Data EvaluateAssignmentExpression(const AssignmentExpression* expression);
		DataTypes::Data EvaluateParethesesExpression(const ParenthesesExpression* expression);
		DataTypes::Data EvaluateNumericLiteral(const NumericLiteral* expression);
		DataTypes::Data EvaluateBooleanLiteral(const BooleanLiteral* expression);
		DataTypes::Data EvaluateUnaryOperation(const UnaryOperation* expression);
		DataTypes::Data EvaluateBinaryOperation(const BinaryOperation* expression);
		DataTypes::Data EvaluateConditionalDeclaration(const ConditionalDeclaration* expression);
		DataTypes::Data EvaluateInlineIfElse(const InlineIfElse* expression);

		DataTypes::Scope* _scope = new DataTypes::Scope();
		NameTable _nameTable = NameTable();

		DataTypes::OperatorsTable _operators = DataTypes::OperatorsTable();
	};
}