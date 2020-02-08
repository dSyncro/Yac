#pragma once

#include "SyntaxTree.h"

#include <yac/Syntax/Statements/Statements.h>

#include <iostream>

namespace Yac {
	namespace Syntax {
		namespace AstPrinter
		{
			void Print(const SyntaxTree& tree) noexcept;
			void Print(const SyntaxTree* tree) noexcept;

			// Expressions
			void PrintNullExpression() noexcept;
			void PrintAssignmentExpression(AssignmentExpression* expression, unsigned int indent = 0) noexcept;
			void PrintBinaryOperation(BinaryOperation* expression, unsigned int indent = 0) noexcept;
			void PrintBooleanLiteral(BooleanLiteral* expression, unsigned int indent = 0) noexcept;
			void PrintNumericLiteral(NumericLiteral* expression, unsigned int indent = 0) noexcept;
			void PrintParenthesesExpression(ParenthesesExpression* expression, unsigned int indent = 0) noexcept;
			void PrintIdentifierExpression(IdentifierExpression* expression, unsigned int indent = 0) noexcept;
			void PrintUnaryOperation(UnaryOperation* expression, unsigned int indent = 0) noexcept;
			void PrintConditionalDeclaration(ConditionalDeclaration* expression, unsigned int indent = 0) noexcept;
			void PrintInlineIfElse(InlineIfElse* expression, unsigned int indent = 0) noexcept;

			// Statements
			void PrintNullStatement() noexcept;
			void PrintIfStatement(IfStatement* statement, unsigned int indent = 0) noexcept;
			void PrintVariableDeclaration(VariableDeclaration* decl, unsigned int indent = 0) noexcept;
			void PrintWhileStatement(WhileStatement* statement, unsigned int indent = 0) noexcept;
			void PrintForStatement(ForStatement* statement, unsigned int indent = 0) noexcept;
			void PrintBlockStatement(BlockStatement* statement, unsigned int indent = 0) noexcept;
			void PrintExpressionStatement(ExpressionStatement* statement, unsigned int indent = 0) noexcept;
		};
	}
}