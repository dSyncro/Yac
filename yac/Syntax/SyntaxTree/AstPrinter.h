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

			void Print(const Statement* statement, std::string indentation, bool isLast) noexcept;
			void Print(const Expression* expression, std::string indentation, bool isLast) noexcept;
			void PrintExpression(const Expression* expression, const std::string& indentation) noexcept;
			void PrintStatement(const Statement* statement, const std::string& indentation) noexcept;
			void PrintNullExpression() noexcept;
			void PrintAssignmentExpression(AssignmentExpression* expression, const std::string& indentation) noexcept;
			void PrintBinaryOperation(BinaryOperation* expression, const std::string& indentation) noexcept;
			void PrintBooleanLiteral(BooleanLiteral* expression, const std::string& indentation) noexcept;
			void PrintNumericLiteral(NumericLiteral* expression, const std::string& indentation) noexcept;
			void PrintParenthesesExpression(ParenthesesExpression* expression, const std::string& indentation) noexcept;
			void PrintIdentifierExpression(IdentifierExpression* expression, const std::string& indentation) noexcept;
			void PrintUnaryOperation(UnaryOperation* expression, const std::string& indentation) noexcept;
			void PrintConditionalDeclaration(ConditionalDeclaration* expression, const std::string& indentation) noexcept;
			void PrintInlineIfElse(InlineIfElse* expression, const std::string& indentation) noexcept;
			void PrintNullStatement() noexcept;
			void PrintIfStatement(IfStatement* statement, const std::string& indentation) noexcept;
			void PrintVariableDeclaration(VariableDeclaration* decl, const std::string& indentation) noexcept;
			void PrintWhileStatement(WhileStatement* statement, const std::string& indentation) noexcept;
			void PrintForStatement(ForStatement* statement, const std::string& indentation) noexcept;
			void PrintBlockStatement(BlockStatement* statement, const std::string& indentation) noexcept;
			void PrintExpressionStatement(ExpressionStatement* statement, const std::string& indentation) noexcept;
		};
	}
}