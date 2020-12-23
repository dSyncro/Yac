#pragma once

#include "VirtualMemory.h"
#include "VariableData.h"

#include <Yac/Syntax/SyntaxTree/SyntaxTree.h>
#include <Yac/Syntax/Expressions.h>
#include <Yac/Syntax/Statements.h>

namespace Yac::Runtime {

	class Executor {

	public:

		Executor(const Syntax::SyntaxTree& tree) : _tree(tree) {}
		~Executor() = default;
		int execute();

	private:

		void evaluateStatement(const Syntax::Statement* statement);
		VariableData evaluateExpression(const Syntax::Expression* expression);

		void evaluateBlockStatement(const Syntax::BlockStatement* statement);
		void evaluateVariableDeclarationStatement(const Syntax::VariableDeclarationStatement* statement);
		void evaluateIfStatement(const Syntax::IfStatement* statement);
		void evaluateForStatement(const Syntax::ForStatement* statement);
		void evaluateWhileStatement(const Syntax::WhileStatement* statement);
		void evaluateExpressionStatement(const Syntax::ExpressionStatement* statement);

		VariableData evaluateIdentifierExpression(const Syntax::IdentifierExpression* expression);
		VariableData evaluateStringExpression(const Syntax::StringExpression* expression);
		VariableData evaluateAssignmentExpression(const Syntax::AssignmentExpression* expression);
		VariableData evaluateParethesesExpression(const Syntax::ParenthesesExpression* expression);
		VariableData evaluateNumericLiteralExpression(const Syntax::NumericLiteralExpression* expression);
		VariableData evaluateBooleanLiteralExpression(const Syntax::BooleanLiteralExpression* expression);
		VariableData evaluateUnaryOperation(const Syntax::UnaryOperationExpression* expression);
		VariableData evaluateBinaryOperation(const Syntax::BinaryOperationExpression* expression);
		VariableData evaluateConditionalDeclarationExpression(const Syntax::ConditionalDeclarationExpression* expression);
		VariableData evaluateInlineIfElseExpression(const Syntax::InlineIfElseExpression* expression);

		Syntax::SyntaxTree _tree;
		VirtualMemory _memory;
	};
}