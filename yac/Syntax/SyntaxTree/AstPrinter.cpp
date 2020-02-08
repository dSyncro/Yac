#include <iostream>

#include "AstPrinter.h"

#include <yac/Libraries/AnsiStyle/AnsiStyle.h>

using namespace Yac::Syntax;
using namespace AnsiStyle;

namespace Yac {
	namespace Syntax {
		namespace AstPrinter {


			/*

			void PrintTree(const Statement* statement, std::string indent = "", bool isLast = true)
			{
				const char* marker = isLast ? "└──" : "├──";

				Console::Write(indent);
				if (indent != "") Console::Write(marker);

				Print(statement, indent)

				// Write Node
				Console::SetForegroundColor(Forecolors::Blue);
				//string text = GetText(node);
				//writer.Write(text);
				Console::Reset();

				Console::NewLine();
				indent += isLast ? "   " : "│   ";
			}

			*/
			

			void Print(const SyntaxTree& tree) noexcept { Print(tree.root(), 0); }
			void Print(const SyntaxTree* tree) noexcept { Print(tree->root(), 0); }

			void Print(const Expression* expression, unsigned int indent) noexcept
			{
				if (!expression) return;

				switch (expression->type())
				{

					case ExpressionType::None: return PrintNullExpression();
					case ExpressionType::AssignmentExpression: return PrintAssignmentExpression((AssignmentExpression*)expression, indent);
					case ExpressionType::BinaryOperation: return PrintBinaryOperation((BinaryOperation*)expression, indent);
					case ExpressionType::BooleanLiteral: return PrintBooleanLiteral((BooleanLiteral*)expression, indent);
					case ExpressionType::IdentifierExpression: return PrintIdentifierExpression((IdentifierExpression*)expression, indent);
					case ExpressionType::NumericLiteral: return PrintNumericLiteral((NumericLiteral*)expression, indent);
					case ExpressionType::ParenthesesExpression: return PrintParenthesesExpression((ParenthesesExpression*)expression, indent);
					case ExpressionType::UnaryOperation: return PrintUnaryOperation((UnaryOperation*)expression, indent);
					case ExpressionType::ConditionalDeclaration: return PrintConditionalDeclaration((ConditionalDeclaration*)expression, indent);
					case ExpressionType::InlineIfElse: return PrintInlineIfElse((InlineIfElse*)expression, indent);

					default: return;
				}
			}

			void Print(const Statement* statement, unsigned int indent) noexcept
			{
				if (!statement) return;

				switch (statement->type())
				{

					case StatementType::None: return PrintNullStatement();
					case StatementType::If: return PrintIfStatement((IfStatement*)statement, indent);
					case StatementType::VariableDeclaration: return PrintVariableDeclaration((VariableDeclaration*)statement, indent);
					case StatementType::While: return PrintWhileStatement((WhileStatement*)statement, indent);
					case StatementType::For: return PrintForStatement((ForStatement*)statement, indent);
					case StatementType::Block: return PrintBlockStatement((BlockStatement*)statement, indent);
					case StatementType::Expression: return PrintExpressionStatement((ExpressionStatement*)statement, indent);

					default: return;
				}
			}

			// Expressions

			void PrintNullExpression() noexcept
			{
				std::cout << "No Expression" << std::endl;
			}

			void PrintAssignmentExpression(AssignmentExpression* expression, unsigned int indent) noexcept
			{
				std::cout << std::string(indent, '\t') << "AssignmentExpression:" << std::endl;
				indent++;
				std::cout << std::string(indent, '\t') << "id = " << expression->identifier() << std::endl;
				std::cout << std::string(indent, '\t') << "operatorID = " << (unsigned int)expression->assignmentOperator() << std::endl;
				Print(expression->expression(), indent);
			}

			void PrintBinaryOperation(BinaryOperation* expression, unsigned int indent) noexcept
			{
				std::cout << std::string(indent, '\t') << "BinaryOperation:" << std::endl;
				indent++;
				Print(expression->left(), indent);
				std::cout << std::string(indent, '\t') << (unsigned int)expression->operation() << std::endl;
				Print(expression->right(), indent);
			}

			void PrintBooleanLiteral(BooleanLiteral* expression, unsigned int indent) noexcept
			{
				std::cout << std::string(indent, '\t') << "BoolLiteral:" << std::endl;
				indent++;
				std::cout << std::string(indent, '\t') << expression->value() << std::endl;
			}

			void PrintNumericLiteral(NumericLiteral* expression, unsigned int indent) noexcept
			{
				std::cout << std::string(indent, '\t') << "NumLiteral:" << std::endl;
				indent++;
				std::cout << std::string(indent, '\t') << (unsigned int)expression->base() << std::endl;
				std::cout << std::string(indent, '\t') << (unsigned int)expression->numeric_type() << std::endl;
				std::cout << std::string(indent, '\t') << expression->text() << std::endl;
			}

			void PrintParenthesesExpression(ParenthesesExpression* expression, unsigned int indent) noexcept
			{
				std::cout << std::string(indent, '\t') << "ParenthesesExpression:" << std::endl;
				indent++;
				Print(expression->expression(), indent);
			}

			void PrintIdentifierExpression(IdentifierExpression* expression, unsigned int indent) noexcept
			{
				std::cout << std::string(indent, '\t') << "IdExpression:" << std::endl;
				indent++;
				std::cout << std::string(indent, '\t') << expression->identifier() << std::endl;
			}

			void PrintUnaryOperation(UnaryOperation* expression, unsigned int indent) noexcept
			{
				std::cout << std::string(indent, '\t') << "UnaryOperation:" << std::endl;
				indent++;
				std::cout << std::string(indent, '\t') << (unsigned int)expression->operation() << std::endl;
				Print(expression->operand(), indent);
			}

			void PrintConditionalDeclaration(ConditionalDeclaration* expression, unsigned int indent) noexcept
			{
				std::cout << std::string(indent, '\t') << "ConditionalDeclaration:" << std::endl;
				indent++;
				std::cout << std::string(indent, '\t') << expression->name() << std::endl;
				Print(expression->initializer(), indent);
			}

			void PrintInlineIfElse(InlineIfElse* expression, unsigned int indent) noexcept
			{
				std::cout << std::string(indent, '\t') << "InlineIfElse:" << std::endl;
				indent++;
				Print(expression->condition(), indent);
				Print(expression->True(), indent);
				Print(expression->False(), indent);
			}

			// Statements

			void PrintNullStatement() noexcept
			{
				std::cout << "No Statement" << std::endl;
			}

			void PrintIfStatement(IfStatement* statement, unsigned int indent) noexcept
			{
				std::cout << std::string(indent, '\t') << "IfStatement: " << std::endl;
				indent++;
				Print(statement->condition(), indent);
				Print(statement->statement(), indent);
				const Statement* elseStatement = statement->elseStatement();
				if (elseStatement) Print(elseStatement, indent);
			}

			void PrintVariableDeclaration(VariableDeclaration* decl, unsigned int indent) noexcept
			{
				std::cout << std::string(indent, '\t') << "VarDecl: " << std::endl;
				indent++;
				std::cout << std::string(indent, '\t') << "name = " << decl->name() << std::endl;
				Print(decl->initializer(), indent);
			}

			void PrintWhileStatement(WhileStatement* statement, unsigned int indent) noexcept
			{
				std::cout << std::string(indent, '\t') << "WhileStatement: " << std::endl;
				indent++;
				Print(statement->condition(), indent);
				Print(statement->statement(), indent);
			}

			void PrintForStatement(ForStatement* statement, unsigned int indent) noexcept
			{
				std::cout << std::string(indent, '\t') << "ForStatement: " << std::endl;
				indent++;
				Print(statement->assignment(), indent);
				Print(statement->condition(), indent);
				Print(statement->update(), indent);
				Print(statement->statement(), indent);
			}

			void PrintBlockStatement(BlockStatement* statement, unsigned int indent) noexcept
			{
				std::cout << std::string(indent, '\t') << "BlockStatement: " << std::endl;
				indent++;

				for (const Statement* s : statement->statements())
					Print(s, indent);
			}

			void PrintExpressionStatement(ExpressionStatement* statement, unsigned int indent) noexcept
			{
				std::cout << std::string(indent, '\t') << "ExpressionStatement: " << std::endl;
				indent++;
				Print(statement->expression(), indent);
			}
		}
	}
}