#pragma once

#include "SyntaxTree.h"

#include <AnsiStyle.h>

#include <Yac/Syntax/Statements.h>
#include <Yac/Syntax/Expressions.h>

#include <iostream>

namespace Yac::Syntax {

	class AstPrinter {

	public:

		struct FormattingOptions {
			AnsiStyle::Forecolors DecoratorsColor = AnsiStyle::Forecolors::White;
			AnsiStyle::Forecolors StatementColor = AnsiStyle::Forecolors::Cyan;
			AnsiStyle::Forecolors ExpressionColor = AnsiStyle::Forecolors::Yellow;
			AnsiStyle::Forecolors DataColor = AnsiStyle::Forecolors::White;
			AnsiStyle::Forecolors LabelColor = AnsiStyle::Forecolors::Green;
		};

		AstPrinter() = delete;

		static FormattingOptions formattingOptions;

		static void print(const SyntaxTree& tree) noexcept;
		static void print(const SyntaxTree* tree) noexcept;

	private:

		static void print(const Statement* statement, std::string indentation, bool isLast) noexcept;
		static void print(const Expression* expression, std::string indentation, bool isLast) noexcept;

		static void printIndentation(std::string& indentation, bool isLast) noexcept;
		static void printData(const std::string& label, const std::string& value) noexcept;
		static void printDecoration(const std::string& decoration) noexcept;

		static void printExpression(const Expression* expression, const std::string& indentation) noexcept;
		static void printStatement(const Statement* statement, const std::string& indentation) noexcept;

		// Expressions

		static void printNullExpression() noexcept;
		static void printAssignmentExpression(AssignmentExpression* expression, const std::string& indentation) noexcept;
		static void printBinaryOperation(BinaryOperationExpression* expression, const std::string& indentation) noexcept;
		static void printBooleanLiteralExpression(BooleanLiteralExpression* expression, const std::string& indentation) noexcept;
		static void printNumericLiteralExpression(NumericLiteralExpression* expression, const std::string& indentation) noexcept;
		static void printParenthesesExpression(ParenthesesExpression* expression, const std::string& indentation) noexcept;
		static void printIdentifierExpression(IdentifierExpression* expression, const std::string& indentation) noexcept;
		static void printStringExpression(StringLiteralExpression* expression, const std::string& indentation) noexcept;
		static void printUnaryOperation(UnaryOperationExpression* expression, const std::string& indentation) noexcept;
		static void printConditionalDeclarationExpression(ConditionalDeclarationExpression* expression, const std::string& indentation) noexcept;
		static void printInlineIfElseExpression(InlineIfElseExpression* expression, const std::string& indentation) noexcept;

		// Statements

		static void printNullStatement() noexcept;
		static void printIfStatement(IfStatement* statement, const std::string& indentation) noexcept;
		static void printVariableDeclarationStatement(VariableDeclarationStatement* statement, const std::string& indentation) noexcept;
		static void printWhileStatement(WhileStatement* statement, const std::string& indentation) noexcept;
		static void printForStatement(ForStatement* statement, const std::string& indentation) noexcept;
		static void printBlockStatement(BlockStatement* statement, const std::string& indentation) noexcept;
		static void printExpressionStatement(ExpressionStatement* statement, const std::string& indentation) noexcept;

	};

}