#include <iostream>

#include "AstPrinter.h"

#include <yac/Libraries/AnsiStyle/AnsiStyle.h>

using namespace Yac::Syntax;
using namespace AnsiStyle;

namespace Yac {
	namespace Syntax {
		namespace AstPrinter {

			void Print(const SyntaxTree& tree) noexcept { Print(tree.root(), "", true); }
			void Print(const SyntaxTree* tree) noexcept { Print(tree->root(), "", true); }

			void Print(const Statement* statement, std::string indentation, bool isLast) noexcept
			{
				Console::Write(indentation, isLast ? "`---" : "|---");

				indentation.append(isLast ? "\t" : "|   ");

				Console::SetForegroundColor(Forecolors::Blue);
				PrintStatement(statement, indentation);
				Console::Reset();
			}

			void Print(const Expression* expression, std::string indentation, bool isLast) noexcept
			{
				Console::Write(indentation, isLast ? "`---" : "|---");

				indentation.append(isLast ? "\t" : "|   ");

				Console::SetForegroundColor(Forecolors::Red);
				PrintExpression(expression, indentation);
				Console::Reset();
			}

			void PrintExpression(const Expression* expression, const std::string& indentation) noexcept
			{
				if (!expression) return;

				switch (expression->type())
				{

					case ExpressionType::None: return PrintNullExpression();
					case ExpressionType::AssignmentExpression: return PrintAssignmentExpression((AssignmentExpression*)expression, indentation);
					case ExpressionType::BinaryOperation: return PrintBinaryOperation((BinaryOperation*)expression, indentation);
					case ExpressionType::BooleanLiteral: return PrintBooleanLiteral((BooleanLiteral*)expression, indentation);
					case ExpressionType::IdentifierExpression: return PrintIdentifierExpression((IdentifierExpression*)expression, indentation);
					case ExpressionType::NumericLiteral: return PrintNumericLiteral((NumericLiteral*)expression, indentation);
					case ExpressionType::ParenthesesExpression: return PrintParenthesesExpression((ParenthesesExpression*)expression, indentation);
					case ExpressionType::UnaryOperation: return PrintUnaryOperation((UnaryOperation*)expression, indentation);
					case ExpressionType::ConditionalDeclaration: return PrintConditionalDeclaration((ConditionalDeclaration*)expression, indentation);
					case ExpressionType::InlineIfElse: return PrintInlineIfElse((InlineIfElse*)expression, indentation);

					default: return;
				}
			}

			void PrintStatement(const Statement* statement, const std::string& indentation) noexcept
			{
				if (!statement) return;

				switch (statement->type())
				{

					case StatementType::None: return PrintNullStatement();
					case StatementType::If: return PrintIfStatement((IfStatement*)statement, indentation);
					case StatementType::VariableDeclaration: return PrintVariableDeclaration((VariableDeclaration*)statement, indentation);
					case StatementType::While: return PrintWhileStatement((WhileStatement*)statement, indentation);
					case StatementType::For: return PrintForStatement((ForStatement*)statement, indentation);
					case StatementType::Block: return PrintBlockStatement((BlockStatement*)statement, indentation);
					case StatementType::Expression: return PrintExpressionStatement((ExpressionStatement*)statement, indentation);

					default: return;
				}
			}

			// Expressions

			void PrintNullExpression() noexcept
			{
				Console::WriteLine("No Expression");
			}

			void PrintAssignmentExpression(AssignmentExpression* expression, const std::string& indentation) noexcept
			{
				Console::WriteLine("AssignmentExpression: ");
				Console::WriteLine(indentation, "|---", "id = '", expression->identifier(), '\'');
				Console::WriteLine(indentation, "|---", "operatorID = ", (unsigned int)expression->assignmentOperator());
				Print(expression->expression(), indentation, true);
			}

			void PrintBinaryOperation(BinaryOperation* expression, const std::string& indentation) noexcept
			{
				Console::WriteLine("BinaryOperation: ");
				Print(expression->left(), indentation, false);
				Console::WriteLine(indentation, "|---", (unsigned int)expression->operation());
				Print(expression->right(), indentation, true);
			}

			void PrintBooleanLiteral(BooleanLiteral* expression, const std::string& indentation) noexcept
			{
				Console::WriteLine("BooleanLiteral: ");
				Console::WriteLine(indentation, "`---", expression->value());
			}

			void PrintNumericLiteral(NumericLiteral* expression, const std::string& indentation) noexcept
			{
				Console::WriteLine("NumericLiteral: ");
				Console::WriteLine(indentation, "|---", (unsigned int)expression->base());
				Console::WriteLine(indentation, "|---", (unsigned int)expression->numeric_type());
				Console::WriteLine(indentation, "`---", expression->text());
			}

			void PrintParenthesesExpression(ParenthesesExpression* expression, const std::string& indentation) noexcept
			{
				Console::WriteLine("ParenthesesExpression: ");
				Print(expression->expression(), indentation, true);
			}

			void PrintIdentifierExpression(IdentifierExpression* expression, const std::string& indentation) noexcept
			{
				Console::WriteLine("IdentifierExpression: ");
				Console::WriteLine(indentation, "`---", expression->identifier());
			}

			void PrintUnaryOperation(UnaryOperation* expression, const std::string& indentation) noexcept
			{
				Console::WriteLine("UnaryOperation: ");
				Console::WriteLine(indentation, "|---", (unsigned int)expression->operation());
				Print(expression->operand(), indentation, true);
			}

			void PrintConditionalDeclaration(ConditionalDeclaration* expression, const std::string& indentation) noexcept
			{
				Console::WriteLine("ConditionalDeclaration: ");
				Console::WriteLine(indentation, "|---", expression->name());
				Print(expression->initializer(), indentation, true);
			}

			void PrintInlineIfElse(InlineIfElse* expression, const std::string& indentation) noexcept
			{
				Console::WriteLine("InlineIfElse: ");
				Print(expression->condition(), indentation, false);
				Print(expression->True(), indentation, false);
				Print(expression->False(), indentation, false);
			}

			// Statements

			void PrintNullStatement() noexcept
			{
				Console::WriteLine("No Statement");
			}

			void PrintIfStatement(IfStatement* statement, const std::string& indentation) noexcept
			{
				Console::WriteLine("IfStatement: ");
				Print(statement->condition(), indentation, false);
				const Statement* elseStatement = statement->elseStatement();
				Print(statement->statement(), indentation, elseStatement ? false : true);
				if (elseStatement) Print(elseStatement, indentation, true);
				
			}

			void PrintVariableDeclaration(VariableDeclaration* decl, const std::string& indentation) noexcept
			{
				Console::WriteLine("VariableDeclaration: ");
				Console::WriteLine(indentation, "name = ", decl->name());
				Print(decl->initializer(), indentation, true);
			}

			void PrintWhileStatement(WhileStatement* statement, const std::string& indentation) noexcept
			{
				Console::WriteLine("WhileStatement: ");
				Print(statement->condition(), indentation, false);
				Print(statement->statement(), indentation, true);
			}

			void PrintForStatement(ForStatement* statement, const std::string& indentation) noexcept
			{
				Console::WriteLine("ForStatement: ");
				Print(statement->assignment(), indentation, false);
				Print(statement->condition(), indentation, false);
				Print(statement->update(), indentation, false);
				Print(statement->statement(), indentation, true);
			}

			void PrintBlockStatement(BlockStatement* statement, const std::string& indentation) noexcept
			{
				Console::WriteLine("BlockStatement: ");

				const std::vector<Statement*>& statements = statement->statements();
				for (unsigned int i = 0; i < statements.size() - 1; i++)
					Print(statements[i], indentation, false);
				Print(statements[statements.size() - 1], indentation, true);
			}

			void PrintExpressionStatement(ExpressionStatement* statement, const std::string& indentation) noexcept
			{
				Console::WriteLine("ExpressionStatement: ");
				Print(statement->expression(), indentation, true);
			}
		}
	}
}