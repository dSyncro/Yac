#include "SyntaxTree.h"

#include <iostream>

#include <yac/Syntax/Parser/Parser.h>
#include <yac/Errors/ErrorList.h>
#include <yac/Syntax/Statements/Statements.h>

using namespace Yac::Syntax;
using namespace Yac::Errors;

SyntaxTree::SyntaxTree(std::string& source)
{
	Parser parser = Parser(source);
	_root = parser.Parse();
	ErrorList& e = parser.errors();
	if (parser.errors().Any())
	{
		for (unsigned int i = 0; i < e.Count(); i++)
			std::cout << e[i].message() << std::endl;
	}
	else Print(_root);
	e.Clear();
}

SyntaxTree::~SyntaxTree()
{
	delete _root;
}

void SyntaxTree::Print(const Expression* ptr, unsigned int indent) const noexcept
{
	switch (ptr->type())
	{
		case ExpressionType::None: {
			std::cout << "No Expression" << std::endl;
			return;
		}
		case ExpressionType::AssignmentExpression: {
			AssignmentExpression* assign = (AssignmentExpression*)ptr;
			std::cout << std::string(indent, '\t') << "AssignmentExpression:" << std::endl;
			indent++;
			std::cout << std::string(indent, '\t') << "id = " << assign->identifier() << std::endl;
			Print(assign->expression(), indent);
			return;
		}
		case ExpressionType::BinaryOperation: {
			BinaryOperation* b = (BinaryOperation*)ptr;
			std::cout << std::string(indent, '\t') << "BinaryOperation:" << std::endl;
			indent++;
			Print(b->left(), indent);
			std::cout << std::string(indent, '\t') << (unsigned int)b->operation() << std::endl;
			Print(b->right(), indent);
			return;
		}
		case ExpressionType::BooleanLiteral: {
			BooleanLiteral* bo = (BooleanLiteral*)ptr;
			std::cout << std::string(indent, '\t') << "BoolLiteral:" << std::endl;
			indent++;
			std::cout << std::string(indent, '\t') << bo->value() << std::endl;
			return;
		}
		case ExpressionType::IdentifierExpression: {
			IdentifierExpression* id = (IdentifierExpression*)ptr;
			std::cout << std::string(indent, '\t') << "IdExpression:" << std::endl;
			indent++;
			std::cout << std::string(indent, '\t') << id->identifier() << std::endl;
			return;
		}
		case ExpressionType::NumericLiteral: {
			NumericLiteral* num = (NumericLiteral*)ptr;
			std::cout << std::string(indent, '\t') << "NumLiteral:" << std::endl;
			indent++;
			std::cout << std::string(indent, '\t') << (unsigned int)num->base() << std::endl;
			std::cout << std::string(indent, '\t') << (unsigned int)num->numeric_type() << std::endl;
			std::cout << std::string(indent, '\t') << num->text() << std::endl;
			return;
		}
		case ExpressionType::ParenthesesExpression: {
			ParenthesesExpression* par = (ParenthesesExpression*)ptr;
			std::cout << std::string(indent, '\t') << "ParenthesesExpression:" << std::endl;
			indent++;
			Print(par->expression(), indent);
			return;
		}	
		case ExpressionType::UnaryOperation: {
			UnaryOperation* un = (UnaryOperation*)ptr;
			std::cout << std::string(indent, '\t') << "UnaryOperation:" << std::endl;
			indent++;
			std::cout << std::string(indent, '\t') << (unsigned int)un->operation() << std::endl;
			Print(un->operand(), indent);
			return;
		}
			
		default: return;
	}
}

void SyntaxTree::Print(const Statement* ptr, unsigned int indent) const noexcept
{
	switch (ptr->type())
	{
		case StatementType::None: {
			std::cout << "No Statement" << std::endl;
			return;
		}
		case StatementType::If: {
			IfStatement* If = (IfStatement*)ptr;
			std::cout << std::string(indent, '\t') << "IfStatement: " << std::endl;
			indent++;
			Print(If->condition(), indent);
			Print(If->statement(), indent);
			const Statement* elseStatement = If->elseStatement();
			if (elseStatement) Print(elseStatement, indent);
			return;
		}
		case StatementType::VariableDeclaration: {
			VariableDeclaration* Decl = (VariableDeclaration*)ptr;
			std::cout << std::string(indent, '\t') << "VarDecl: " << std::endl;
			indent++;
			std::cout << std::string(indent, '\t') << "name = " << Decl->name() << std::endl;
			Print(Decl->initializer(), indent);
			return;
		}
		case StatementType::While: {
			WhileStatement* While = (WhileStatement*)ptr;
			std::cout << std::string(indent, '\t') << "WhileStatement: " << std::endl;
			indent++;
			Print(While->condition(), indent);
			Print(While->statement(), indent);
			return;
		}
		case StatementType::For: {
			ForStatement* For = (ForStatement*)ptr;
			std::cout << std::string(indent, '\t') << "ForStatement: " << std::endl;
			indent++;
			Print(For->assignment(), indent);
			Print(For->condition(), indent);
			Print(For->update(), indent);
			Print(For->statement(), indent);
			return;
		}
		case StatementType::Block: {
			std::cout << std::string(indent, '\t') << "BlockStatement: " << std::endl;
			indent++;
			for (const Statement* statement : ((BlockStatement*)ptr)->statements())
				Print(statement, indent);
			return;
		}
		case StatementType::Expression: {
			std::cout << std::string(indent, '\t') << "ExpressionStatement: " << std::endl;
			indent++;
			Print(((ExpressionStatement*)ptr)->expression(), indent);
		}
		default: return;
	}
}