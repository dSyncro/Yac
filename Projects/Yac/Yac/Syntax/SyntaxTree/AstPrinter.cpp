#include <iostream>

#include "AstPrinter.h"

#include <Console.h>

#include <Yac/Core/Primitives.h>

using namespace Yac::Syntax;
using namespace AnsiStyle;

AstPrinter::FormattingOptions AstPrinter::formattingOptions = FormattingOptions();

void AstPrinter::print(const SyntaxTree& tree) noexcept { print(tree.getRoot(), "", true); }
void AstPrinter::print(const SyntaxTree* tree) noexcept { print(tree->getRoot(), "", true); }

void AstPrinter::print(const Statement* statement, std::string indentation, bool isLast) noexcept
{
	printIndentation(indentation, isLast);

	Console::setForegroundColor(formattingOptions.StatementColor);
	printStatement(statement, indentation);
	Console::reset();
}

void AstPrinter::print(const Expression* expression, std::string indentation, bool isLast) noexcept
{
	printIndentation(indentation, isLast);

	Console::setForegroundColor(formattingOptions.ExpressionColor);
	printExpression(expression, indentation);
	Console::reset();
}

void AstPrinter::printIndentation(std::string& indentation, bool isLast) noexcept
{
	Console::setForegroundColor(formattingOptions.DecoratorsColor);
	if (!indentation.empty()) Console::write(indentation, isLast ? "`---" : "|---");
	indentation.append(isLast ? "\t" : "|   ");
	Console::reset();
}

void AstPrinter::printExpression(const Expression* expression, const std::string& indentation) noexcept
{
	if (!expression) return printNullExpression();

	switch (expression->getType())
	{

		case ExpressionType::None: return printNullExpression();
		case ExpressionType::Assignment: return printAssignmentExpression((AssignmentExpression*)expression, indentation);
		case ExpressionType::BinaryOperation: return printBinaryOperation((BinaryOperationExpression*)expression, indentation);
		case ExpressionType::BooleanLiteral: return printBooleanLiteralExpression((BooleanLiteralExpression*)expression, indentation);
		case ExpressionType::Identifier: return printIdentifierExpression((IdentifierExpression*)expression, indentation);
		case ExpressionType::StringLiteral: return printStringExpression((StringLiteralExpression*)expression, indentation);
		case ExpressionType::NumericLiteral: return printNumericLiteralExpression((NumericLiteralExpression*)expression, indentation);
		case ExpressionType::Parentheses: return printParenthesesExpression((ParenthesesExpression*)expression, indentation);
		case ExpressionType::UnaryOperation: return printUnaryOperation((UnaryOperationExpression*)expression, indentation);
		case ExpressionType::ConditionalDeclaration: return printConditionalDeclarationExpression((ConditionalDeclarationExpression*)expression, indentation);
		case ExpressionType::InlineIfElse: return printInlineIfElseExpression((InlineIfElseExpression*)expression, indentation);

		default: return printNullExpression();
	}
}

void AstPrinter::printStatement(const Statement* statement, const std::string& indentation) noexcept
{
	if (!statement) return printNullStatement();

	switch (statement->getType())
	{

		case StatementType::None: return printNullStatement();
		case StatementType::If: return printIfStatement((IfStatement*)statement, indentation);
		case StatementType::VariableDeclaration: return printVariableDeclarationStatement((VariableDeclarationStatement*)statement, indentation);
		case StatementType::While: return printWhileStatement((WhileStatement*)statement, indentation);
		case StatementType::For: return printForStatement((ForStatement*)statement, indentation);
		case StatementType::Block: return printBlockStatement((BlockStatement*)statement, indentation);
		case StatementType::Expression: return printExpressionStatement((ExpressionStatement*)statement, indentation);

		default: return printNullStatement();
	}
}

// Expressions

void AstPrinter::printNullExpression() noexcept
{
	Console::writeLine("No Expression");
}

void AstPrinter::printAssignmentExpression(AssignmentExpression* expression, const std::string& indentation) noexcept
{
	Console::writeLine("AssignmentExpression");

	// Identifier
	printDecoration(indentation + "|---");
	printData("Identifier", expression->getIdentifier());

	// Operator
	printDecoration(indentation + "|---");
	printData("Operator", toString(expression->getAssignmentOperator()));

	// Expression
	print(expression->getExpression(), indentation, true);
}

void AstPrinter::printBinaryOperation(BinaryOperationExpression* expression, const std::string& indentation) noexcept
{
	Console::writeLine("BinaryOperation");

	// Left expression
	print(expression->getLeft(), indentation, false);

	// Operation
	printDecoration(indentation + "|---");
	printData("Operation", toString(expression->getOperator()));

	// Right expression
	print(expression->getRight(), indentation, true);
}

void AstPrinter::printBooleanLiteralExpression(BooleanLiteralExpression* expression, const std::string& indentation) noexcept
{
	Console::writeLine("BooleanLiteral");

	// Value
	printDecoration(indentation + "`---");
	printData("Value", std::to_string(expression->getValue()));
}

void AstPrinter::printNumericLiteralExpression(NumericLiteralExpression* expression, const std::string& indentation) noexcept
{
	Console::writeLine("NumericLiteral");

	// Type
	printDecoration(indentation + "|---");
	printData("Numeric Type", toString(expression->getNumericType()));

	// Value
	printDecoration(indentation + "`---");
	printData("Value", "<Just a reminder to implement this>" /*expression->getText()*/);
}

void AstPrinter::printParenthesesExpression(ParenthesesExpression* expression, const std::string& indentation) noexcept
{
	Console::writeLine("ParenthesesExpression");
	print(expression->getExpression(), indentation, true);
}

void AstPrinter::printIdentifierExpression(IdentifierExpression* expression, const std::string& indentation) noexcept
{
	Console::writeLine("IdentifierExpression");

	// Identifier
	printDecoration(indentation + "`---");
	printData("Identifier", expression->getIdentifier());
}

void AstPrinter::printStringExpression(StringLiteralExpression* expression, const std::string& indentation) noexcept
{
	Console::writeLine("StringExpression");

	// Identifier
	printDecoration(indentation + "`---");
	printData("literal", expression->getText());
}

void AstPrinter::printUnaryOperation(UnaryOperationExpression* expression, const std::string& indentation) noexcept
{
	Console::writeLine("UnaryOperation");

	// Operation
	printDecoration(indentation + "|---");
	printData("Operation", toString(expression->getOperator()));

	// Operand
	print(expression->getOperand(), indentation, true);
}

void AstPrinter::printConditionalDeclarationExpression(ConditionalDeclarationExpression* expression, const std::string& indentation) noexcept
{
	Console::writeLine("ConditionalDeclaration");

	// Name
	printDecoration(indentation + "|---");
	printData("Name", expression->getName());

	// Initializer
	print(expression->getInitializer(), indentation, true);
}

void AstPrinter::printInlineIfElseExpression(InlineIfElseExpression* expression, const std::string& indentation) noexcept
{
	Console::writeLine("InlineIfElse");
	print(expression->getCondition(), indentation, false);
	print(expression->getTrueExpression(), indentation, false);
	print(expression->getFalseExpression(), indentation, true);
}

// Statements

void AstPrinter::printNullStatement() noexcept
{
	Console::writeLine("No Statement");
}

void AstPrinter::printIfStatement(IfStatement* statement, const std::string& indentation) noexcept
{
	Console::writeLine("IfStatement");

	// Condition
	print(statement->getCondition(), indentation, false);

	// Statement - [Else Statement]
	const Statement* elseStatement = statement->getElseStatement();
	print(statement->getStatement(), indentation, elseStatement ? false : true);
	if (elseStatement) print(elseStatement, indentation, true);

}

void AstPrinter::printVariableDeclarationStatement(VariableDeclarationStatement* statement, const std::string& indentation) noexcept
{
	Console::writeLine("VariableDeclaration");

	// Name
	printDecoration(indentation + "|---");
	printData("Name", statement->getName());

	// Initializer
	print(statement->getInitializer(), indentation, true);
}

void AstPrinter::printWhileStatement(WhileStatement* statement, const std::string& indentation) noexcept
{
	Console::writeLine("WhileStatement");
	print(statement->getCondition(), indentation, false); // Condition
	print(statement->getStatement(), indentation, true); // Statement
}

void AstPrinter::printForStatement(ForStatement* statement, const std::string& indentation) noexcept
{
	Console::writeLine("ForStatement");
	print(statement->getAssignment(), indentation, false); // Assignment
	print(statement->getCondition(), indentation, false); // Condition
	print(statement->getUpdate(), indentation, false); // Update
	print(statement->getStatement(), indentation, true); // Statement
}

void AstPrinter::printBlockStatement(BlockStatement* statement, const std::string& indentation) noexcept
{
	Console::writeLine("BlockStatement");

	// Statements
	const std::vector<Statement*>& statements = statement->getStatements();
	for (UIntT i = 0; i < statements.size() - 1; i++)
		print(statements[i], indentation, false);
	print(statements[statements.size() - 1], indentation, true);
}

void AstPrinter::printExpressionStatement(ExpressionStatement* statement, const std::string& indentation) noexcept
{
	Console::writeLine("ExpressionStatement");
	print(statement->getExpression(), indentation, true); // Expression
}

void AstPrinter::printData(const std::string& label, const std::string& value) noexcept
{
	Console::writeColored(formattingOptions.LabelColor, label, ": ");
	Console::writeColoredLine(formattingOptions.DataColor, value);
}

void AstPrinter::printDecoration(const std::string& decoration) noexcept
{
	Console::writeColored(formattingOptions.DecoratorsColor, decoration);
}