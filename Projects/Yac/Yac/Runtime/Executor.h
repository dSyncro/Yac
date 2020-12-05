#pragma once

#include "NameTable.h"

#include "Scope.h"
#include "TypedData.h"
#include "Operators/OperatorsTable.h"

#include <Yac/Syntax/SyntaxTree/SyntaxTree.h>
#include <Yac/Syntax/Expressions/Expressions.h>
#include <Yac/Syntax/Statements/Statements.h>

namespace Yac::Runtime {

	class Executor {

	public:

		int Execute();

	private:

		void EvaluateStatement(const Syntax::Statement* statement);
		TypedData EvaluateExpression(const Syntax::Expression* expression);

		void EvaluateBlockStatement(const Syntax::BlockStatement* statement);
		void EvaluateVariableDeclaration(const Syntax::VariableDeclaration* statement);
		void EvaluateIfStatement(const Syntax::IfStatement* statement);
		void EvaluateForStatement(const Syntax::ForStatement* statement);
		void EvaluateWhileStatement(const Syntax::WhileStatement* statement);
		void EvaluateExpressionStatement(const Syntax::ExpressionStatement* statement);

		TypedData EvaluateIdentifierExpression(const Syntax::IdentifierExpression* expression);
		TypedData EvaluateStringExpression(const Syntax::StringExpression* expression);
		TypedData EvaluateAssignmentExpression(const Syntax::AssignmentExpression* expression);
		TypedData EvaluateParethesesExpression(const Syntax::ParenthesesExpression* expression);
		TypedData EvaluateNumericLiteral(const Syntax::NumericLiteral* expression);
		TypedData EvaluateBooleanLiteral(const Syntax::BooleanLiteral* expression);
		TypedData EvaluateUnaryOperation(const Syntax::UnaryOperation* expression);
		TypedData EvaluateBinaryOperation(const Syntax::BinaryOperation* expression);
		TypedData EvaluateConditionalDeclaration(const Syntax::ConditionalDeclaration* expression);
		TypedData EvaluateInlineIfElse(const Syntax::InlineIfElse* expression);

		Scope* _scope = new Scope();
		NameTable _nameTable = NameTable();
		OperatorsTable _operators = OperatorsTable();
	};
}