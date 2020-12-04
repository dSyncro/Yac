#include <iostream>

#include "AstPrinter.h"

#include <Yac/Libraries/Console/Console.h>
#include <Yac/Core/Primitives.h>

using namespace Yac::Syntax;
using namespace AnsiStyle;

AstPrinter::FormattingOptions AstPrinter::formattingOptions = FormattingOptions();

void AstPrinter::print(const SyntaxTree& tree) noexcept { print(tree.getRoot(), "", true); }
void AstPrinter::print(const SyntaxTree* tree) noexcept { print(tree->getRoot(), "", true); }

void AstPrinter::print(const Statement* statement, std::string indentation, bool isLast) noexcept
{
	printIndentation(indentation, isLast);

	Console::SetForegroundColor(formattingOptions.StatementColor);
	printStatement(statement, indentation);
	Console::Reset();
}

void AstPrinter::print(const Expression* expression, std::string indentation, bool isLast) noexcept
{
	printIndentation(indentation, isLast);

	Console::SetForegroundColor(formattingOptions.ExpressionColor);
	printExpression(expression, indentation);
	Console::Reset();
}

void AstPrinter::printIndentation(std::string& indentation, bool isLast) noexcept
{
	Console::SetForegroundColor(formattingOptions.DecoratorsColor);
	if (!indentation.empty()) Console::Write(indentation, isLast ? "`---" : "|---");
	indentation.append(isLast ? "\t" : "|   ");
	Console::Reset();
}

void AstPrinter::printExpression(const Expression* expression, const std::string& indentation) noexcept
{
	if (!expression) return printNullExpression();

	switch (expression->getType())
	{

		case ExpressionType::None: return printNullExpression();
		case ExpressionType::AssignmentExpression: return printAssignmentExpression((AssignmentExpression*)expression, indentation);
		case ExpressionType::BinaryOperation: return printBinaryOperation((BinaryOperation*)expression, indentation);
		case ExpressionType::BooleanLiteral: return printBooleanLiteral((BooleanLiteral*)expression, indentation);
		case ExpressionType::IdentifierExpression: return printIdentifierExpression((IdentifierExpression*)expression, indentation);
		case ExpressionType::StringExpression: return printStringExpression((StringExpression*)expression, indentation);
		case ExpressionType::NumericLiteral: return printNumericLiteral((NumericLiteral*)expression, indentation);
		case ExpressionType::ParenthesesExpression: return printParenthesesExpression((ParenthesesExpression*)expression, indentation);
		case ExpressionType::UnaryOperation: return printUnaryOperation((UnaryOperation*)expression, indentation);
		case ExpressionType::ConditionalDeclaration: return printConditionalDeclaration((ConditionalDeclaration*)expression, indentation);
		case ExpressionType::InlineIfElse: return printInlineIfElse((InlineIfElse*)expression, indentation);

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
		case StatementType::VariableDeclaration: return printVariableDeclaration((VariableDeclaration*)statement, indentation);
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
	Console::WriteLine("No Expression");
}

void AstPrinter::printAssignmentExpression(AssignmentExpression* expression, const std::string& indentation) noexcept
{
	Console::WriteLine("AssignmentExpression");

	// Identifier
	printDecoration(indentation + "|---");
	printData("Identifier", expression->getIdentifier());

	// Operator
	printDecoration(indentation + "|---");
	printData("Operator", toString(expression->getAssignmentOperator()));

	// Expression
	print(expression->getExpression(), indentation, true);
}

void AstPrinter::printBinaryOperation(BinaryOperation* expression, const std::string& indentation) noexcept
{
	Console::WriteLine("BinaryOperation");

	// Left expression
	print(expression->getLeft(), indentation, false);

	// Operation
	printDecoration(indentation + "|---");
	printData("Operation", toString(expression->getOperation()));

	// Right expression
	print(expression->getRight(), indentation, true);
}

void AstPrinter::printBooleanLiteral(BooleanLiteral* expression, const std::string& indentation) noexcept
{
	Console::WriteLine("BooleanLiteral");

	// Value
	printDecoration(indentation + "`---");
	printData("Value", std::to_string(expression->getValue()));
}

void AstPrinter::printNumericLiteral(NumericLiteral* expression, const std::string& indentation) noexcept
{
	Console::WriteLine("NumericLiteral");

	// Base
	printDecoration(indentation + "|---");
	printData("Numeric Base", toString(expression->getBase()));

	// Type
	printDecoration(indentation + "|---");
	printData("Numeric Type", toString(expression->getNumericType()));

	// Value
	printDecoration(indentation + "`---");
	printData("Value", expression->getText());
}

void AstPrinter::printParenthesesExpression(ParenthesesExpression* expression, const std::string& indentation) noexcept
{
	Console::WriteLine("ParenthesesExpression");
	print(expression->getExpression(), indentation, true);
}

void AstPrinter::printIdentifierExpression(IdentifierExpression* expression, const std::string& indentation) noexcept
{
	Console::WriteLine("IdentifierExpression");

	// Identifier
	printDecoration(indentation + "`---");
	printData("Identifier", expression->getIdentifier());
}

void AstPrinter::printStringExpression(StringExpression* expression, const std::string& indentation) noexcept
{
	Console::WriteLine("StringExpression");

	// Identifier
	printDecoration(indentation + "`---");
	printData("literal", expression->getText());
}

void AstPrinter::printUnaryOperation(UnaryOperation* expression, const std::string& indentation) noexcept
{
	Console::WriteLine("UnaryOperation");

	// Operation
	printDecoration(indentation + "|---");
	printData("Operation", toString(expression->getOperation()));

	// Operand
	print(expression->getOperand(), indentation, true);
}

void AstPrinter::printConditionalDeclaration(ConditionalDeclaration* expression, const std::string& indentation) noexcept
{
	Console::WriteLine("ConditionalDeclaration");

	// Name
	printDecoration(indentation + "|---");
	printData("Name", expression->getName());

	// Initializer
	print(expression->getInitializer(), indentation, true);
}

void AstPrinter::printInlineIfElse(InlineIfElse* expression, const std::string& indentation) noexcept
{
	Console::WriteLine("InlineIfElse");
	print(expression->getCondition(), indentation, false);
	print(expression->getTrueExpression(), indentation, false);
	print(expression->getFalseExpression(), indentation, true);
}

// Statements

void AstPrinter::printNullStatement() noexcept
{
	Console::WriteLine("No Statement");
}

void AstPrinter::printIfStatement(IfStatement* statement, const std::string& indentation) noexcept
{
	Console::WriteLine("IfStatement");

	// Condition
	print(statement->getCondition(), indentation, false);

	// Statement - [Else Statement]
	const Statement* elseStatement = statement->getElseStatement();
	print(statement->getStatement(), indentation, elseStatement ? false : true);
	if (elseStatement) print(elseStatement, indentation, true);

}

void AstPrinter::printVariableDeclaration(VariableDeclaration* statement, const std::string& indentation) noexcept
{
	Console::WriteLine("VariableDeclaration");

	// Name
	printDecoration(indentation + "|---");
	printData("Name", statement->getName());

	// Initializer
	print(statement->getInitializer(), indentation, true);
}

void AstPrinter::printWhileStatement(WhileStatement* statement, const std::string& indentation) noexcept
{
	Console::WriteLine("WhileStatement");
	print(statement->getCondition(), indentation, false); // Condition
	print(statement->getStatement(), indentation, true); // Statement
}

void AstPrinter::printForStatement(ForStatement* statement, const std::string& indentation) noexcept
{
	Console::WriteLine("ForStatement");
	print(statement->getAssignment(), indentation, false); // Assignment
	print(statement->getCondition(), indentation, false); // Condition
	print(statement->getUpdate(), indentation, false); // Update
	print(statement->getStatement(), indentation, true); // Statement
}

void AstPrinter::printBlockStatement(BlockStatement* statement, const std::string& indentation) noexcept
{
	Console::WriteLine("BlockStatement");

	// Statements
	const std::vector<Statement*>& statements = statement->getStatements();
	for (UIntT i = 0; i < statements.size() - 1; i++)
		print(statements[i], indentation, false);
	print(statements[statements.size() - 1], indentation, true);
}

void AstPrinter::printExpressionStatement(ExpressionStatement* statement, const std::string& indentation) noexcept
{
	Console::WriteLine("ExpressionStatement");
	print(statement->getExpression(), indentation, true); // Expression
}

void AstPrinter::printData(const std::string& label, const std::string& value) noexcept
{
	Console::WriteColored(formattingOptions.LabelColor, label, ": ");
	Console::WriteColoredLine(formattingOptions.DataColor, value);
}

void AstPrinter::printDecoration(const std::string& decoration) noexcept
{
	Console::WriteColored(formattingOptions.DecoratorsColor, decoration);
}