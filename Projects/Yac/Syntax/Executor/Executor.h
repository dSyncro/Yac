#pragma once

#include "Scope.h"

#include <Syntax/Binding/BoundObject.h>
#include <Syntax/SyntaxTree/SyntaxTree.h>
#include <Syntax/Expressions/Expressions.h>
#include <Syntax/Statements/Statements.h>

namespace Yac::Syntax {

	using namespace Yac::Syntax::Binding;

	class Executor {

	public:

		int Execute();

	private:

		void EvaluateStatement(const Statement* statement);
		BoundObject* EvaluateExpression(const Expression* expression);

		void EvaluateBlockStatement(const BlockStatement* statement);
		void EvaluateVariableDeclaration(const VariableDeclaration* statement);
		void EvaluateIfStatement(const IfStatement* statement);
		void EvaluateForStatement(const ForStatement* statement);
		void EvaluateWhileStatement(const WhileStatement* statement);
		void EvaluateExpressionStatement(const ExpressionStatement* statement);

		BoundObject* EvaluateIdentifierExpression(const IdentifierExpression* expression);
		BoundObject* EvaluateStringExpression(const StringExpression* expression);
		BoundObject* EvaluateAssignmentExpression(const AssignmentExpression* expression);
		BoundObject* EvaluateParethesesExpression(const ParenthesesExpression* expression);
		BoundObject* EvaluateNumericLiteral(const NumericLiteral* expression);
		BoundObject* EvaluateBooleanLiteral(const BooleanLiteral* expression);
		BoundObject* EvaluateUnaryOperation(const UnaryOperation* expression);
		BoundObject* EvaluateBinaryOperation(const BinaryOperation* expression);
		BoundObject* EvaluateConditionalDeclaration(const ConditionalDeclaration* expression);
		BoundObject* EvaluateInlineIfElse(const InlineIfElse* expression);

		Scope _scope = Scope();

	};
}