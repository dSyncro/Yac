#include <iostream>

#include "AstPrinter.h"

#include <Libraries/Console/Console.h>

#include <Syntax/Statements/Statements.h>
#include <Syntax/Expressions/Expressions.h>

using namespace Yac::Syntax;
using namespace AnsiStyle;

namespace Yac {
	namespace Syntax {
		namespace AstPrinter {

			// Private Members
			namespace {

				void Print(const Statement* statement, std::string indentation, bool isLast) noexcept;
				void Print(const Expression* expression, std::string indentation, bool isLast) noexcept;

				void PrintIndentation(std::string& indentation, bool isLast) noexcept;

				void PrintExpression(const Expression* expression, const std::string& indentation) noexcept;
				void PrintStatement(const Statement* statement, const std::string& indentation) noexcept;

				void PrintNullExpression() noexcept;
				void PrintAssignmentExpression(AssignmentExpression* expression, const std::string& indentation) noexcept;
				void PrintBinaryOperation(BinaryOperation* expression, const std::string& indentation) noexcept;
				void PrintBooleanLiteral(BooleanLiteral* expression, const std::string& indentation) noexcept;
				void PrintNumericLiteral(NumericLiteral* expression, const std::string& indentation) noexcept;
				void PrintParenthesesExpression(ParenthesesExpression* expression, const std::string& indentation) noexcept;
				void PrintIdentifierExpression(IdentifierExpression* expression, const std::string& indentation) noexcept;
				void PrintStringExpression(StringExpression* expression, const std::string& indentation) noexcept;
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
				void PrintData(const std::string& label, const std::string& value) noexcept;
				void PrintDecoration(const std::string& decoration) noexcept;

				void Print(const Statement* statement, std::string indentation, bool isLast) noexcept
				{
					PrintIndentation(indentation, isLast);

					Console::SetForegroundColor(formattingOptions.StatementColor);
					PrintStatement(statement, indentation);
					Console::Reset();
				}

				void Print(const Expression* expression, std::string indentation, bool isLast) noexcept
				{
					PrintIndentation(indentation, isLast);

					Console::SetForegroundColor(formattingOptions.ExpressionColor);
					PrintExpression(expression, indentation);
					Console::Reset();
				}

				void PrintIndentation(std::string& indentation, bool isLast) noexcept
				{
					Console::SetForegroundColor(formattingOptions.DecoratorsColor);
					if (!indentation.empty()) Console::Write(indentation, isLast ? "`---" : "|---");
					indentation.append(isLast ? "\t" : "|   ");
					Console::Reset();
				}

				void PrintExpression(const Expression* expression, const std::string& indentation) noexcept
				{
					if (!expression) return PrintNullExpression();

					switch (expression->type())
					{

						case ExpressionType::None: return PrintNullExpression();
						case ExpressionType::AssignmentExpression: return PrintAssignmentExpression((AssignmentExpression*)expression, indentation);
						case ExpressionType::BinaryOperation: return PrintBinaryOperation((BinaryOperation*)expression, indentation);
						case ExpressionType::BooleanLiteral: return PrintBooleanLiteral((BooleanLiteral*)expression, indentation);
						case ExpressionType::IdentifierExpression: return PrintIdentifierExpression((IdentifierExpression*)expression, indentation);
						case ExpressionType::StringExpression: return PrintStringExpression((StringExpression*)expression, indentation);
						case ExpressionType::NumericLiteral: return PrintNumericLiteral((NumericLiteral*)expression, indentation);
						case ExpressionType::ParenthesesExpression: return PrintParenthesesExpression((ParenthesesExpression*)expression, indentation);
						case ExpressionType::UnaryOperation: return PrintUnaryOperation((UnaryOperation*)expression, indentation);
						case ExpressionType::ConditionalDeclaration: return PrintConditionalDeclaration((ConditionalDeclaration*)expression, indentation);
						case ExpressionType::InlineIfElse: return PrintInlineIfElse((InlineIfElse*)expression, indentation);

						default: return PrintNullExpression();
					}
				}

				void PrintStatement(const Statement* statement, const std::string& indentation) noexcept
				{
					if (!statement) return PrintNullStatement();

					switch (statement->type())
					{

						case StatementType::None: return PrintNullStatement();
						case StatementType::If: return PrintIfStatement((IfStatement*)statement, indentation);
						case StatementType::VariableDeclaration: return PrintVariableDeclaration((VariableDeclaration*)statement, indentation);
						case StatementType::While: return PrintWhileStatement((WhileStatement*)statement, indentation);
						case StatementType::For: return PrintForStatement((ForStatement*)statement, indentation);
						case StatementType::Block: return PrintBlockStatement((BlockStatement*)statement, indentation);
						case StatementType::Expression: return PrintExpressionStatement((ExpressionStatement*)statement, indentation);

						default: return PrintNullStatement();
					}
				}

				// Expressions

				void PrintNullExpression() noexcept
				{
					Console::WriteLine("No Expression");
				}

				void PrintAssignmentExpression(AssignmentExpression* expression, const std::string& indentation) noexcept
				{
					Console::WriteLine("AssignmentExpression");

					// Identifier
					PrintDecoration(indentation + "|---");
					PrintData("Identifier", expression->identifier());

					// Operator
					PrintDecoration(indentation + "|---");
					PrintData("Operator", ToString(expression->assignmentOperator()));

					// Expression
					Print(expression->expression(), indentation, true);
				}

				void PrintBinaryOperation(BinaryOperation* expression, const std::string& indentation) noexcept
				{
					Console::WriteLine("BinaryOperation");

					// Left expression
					Print(expression->left(), indentation, false);

					// Operation
					PrintDecoration(indentation + "|---");
					PrintData("Operation", ToString(expression->operation()));

					// Right expression
					Print(expression->right(), indentation, true);
				}

				void PrintBooleanLiteral(BooleanLiteral* expression, const std::string& indentation) noexcept
				{
					Console::WriteLine("BooleanLiteral");

					// Value
					PrintDecoration(indentation + "`---");
					PrintData("Value", std::to_string(expression->value()));
				}

				void PrintNumericLiteral(NumericLiteral* expression, const std::string& indentation) noexcept
				{
					Console::WriteLine("NumericLiteral");

					// Base
					PrintDecoration(indentation + "|---");
					PrintData("Numeric Base", ToString(expression->base()));

					// Type
					PrintDecoration(indentation + "|---");
					PrintData("Numeric Type", ToString(expression->numeric_type()));

					// Value
					PrintDecoration(indentation + "`---");
					PrintData("Value", expression->text());
				}

				void PrintParenthesesExpression(ParenthesesExpression* expression, const std::string& indentation) noexcept
				{
					Console::WriteLine("ParenthesesExpression");
					Print(expression->expression(), indentation, true);
				}

				void PrintIdentifierExpression(IdentifierExpression* expression, const std::string& indentation) noexcept
				{
					Console::WriteLine("IdentifierExpression");

					// Identifier
					PrintDecoration(indentation + "`---");
					PrintData("Identifier", expression->identifier());
				}

				void PrintStringExpression(StringExpression* expression, const std::string& indentation) noexcept
				{
					Console::WriteLine("StringExpression");

					// Identifier
					PrintDecoration(indentation + "`---");
					PrintData("literal", expression->text());
				}

				void PrintUnaryOperation(UnaryOperation* expression, const std::string& indentation) noexcept
				{
					Console::WriteLine("UnaryOperation");

					// Operation
					PrintDecoration(indentation + "|---");
					PrintData("Operation", ToString(expression->operation()));

					// Operand
					Print(expression->operand(), indentation, true);
				}

				void PrintConditionalDeclaration(ConditionalDeclaration* expression, const std::string& indentation) noexcept
				{
					Console::WriteLine("ConditionalDeclaration");

					// Name
					PrintDecoration(indentation + "|---");
					PrintData("Name", expression->name());

					// Initializer
					Print(expression->initializer(), indentation, true);
				}

				void PrintInlineIfElse(InlineIfElse* expression, const std::string& indentation) noexcept
				{
					Console::WriteLine("InlineIfElse");
					Print(expression->condition(), indentation, false);
					Print(expression->True(), indentation, false);
					Print(expression->False(), indentation, true);
				}

				// Statements

				void PrintNullStatement() noexcept
				{
					Console::WriteLine("No Statement");
				}

				void PrintIfStatement(IfStatement* statement, const std::string& indentation) noexcept
				{
					Console::WriteLine("IfStatement");

					// Condition
					Print(statement->condition(), indentation, false);

					// Statement - [Else Statement]
					const Statement* elseStatement = statement->elseStatement();
					Print(statement->statement(), indentation, elseStatement ? false : true);
					if (elseStatement) Print(elseStatement, indentation, true);

				}

				void PrintVariableDeclaration(VariableDeclaration* statement, const std::string& indentation) noexcept
				{
					Console::WriteLine("VariableDeclaration");

					// Name
					PrintDecoration(indentation + "|---");
					PrintData("Name", statement->name());

					// Initializer
					Print(statement->initializer(), indentation, true);
				}

				void PrintWhileStatement(WhileStatement* statement, const std::string& indentation) noexcept
				{
					Console::WriteLine("WhileStatement");
					Print(statement->condition(), indentation, false); // Condition
					Print(statement->statement(), indentation, true); // Statement
				}

				void PrintForStatement(ForStatement* statement, const std::string& indentation) noexcept
				{
					Console::WriteLine("ForStatement");
					Print(statement->assignment(), indentation, false); // Assignment
					Print(statement->condition(), indentation, false); // Condition
					Print(statement->update(), indentation, false); // Update
					Print(statement->statement(), indentation, true); // Statement
				}

				void PrintBlockStatement(BlockStatement* statement, const std::string& indentation) noexcept
				{
					Console::WriteLine("BlockStatement");

					// Statements
					const std::vector<Statement*>& statements = statement->statements();
					for (unsigned int i = 0; i < statements.size() - 1; i++)
						Print(statements[i], indentation, false);
					Print(statements[statements.size() - 1], indentation, true);
				}

				void PrintExpressionStatement(ExpressionStatement* statement, const std::string& indentation) noexcept
				{
					Console::WriteLine("ExpressionStatement");
					Print(statement->expression(), indentation, true); // Expression
				}

				void PrintData(const std::string& label, const std::string& value) noexcept
				{
					Console::WriteColored(formattingOptions.LabelColor, label, ": ");
					Console::WriteColoredLine(formattingOptions.DataColor, value);
				}

				void PrintDecoration(const std::string& decoration) noexcept
				{
					Console::WriteColored(formattingOptions.DecoratorsColor, decoration);
				}
			}

			FormattingOptions formattingOptions = FormattingOptions();

			void Print(const SyntaxTree& tree) noexcept { Print(tree.root(), "", true); }
			void Print(const SyntaxTree* tree) noexcept { Print(tree->root(), "", true); }
		}
	}
}