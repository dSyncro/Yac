#include <iostream>

#include "AstPrinter.h"

#include <yac/Syntax/Statements/Statements.h>

using namespace Yac::Syntax;

namespace Yac {
	namespace Syntax {
		namespace AstPrinter {
			namespace {

				void Print(const Expression* expression, unsigned int indent = 0) noexcept
				{
					if (!expression) return;

					switch (expression->type())
					{

						case ExpressionType::None:
						{
							std::cout << "No Expression" << std::endl;
							return;
						}

						case ExpressionType::AssignmentExpression:
						{
							AssignmentExpression* assign = (AssignmentExpression*)expression;
							std::cout << std::string(indent, '\t') << "AssignmentExpression:" << std::endl;
							indent++;
							std::cout << std::string(indent, '\t') << "id = " << assign->identifier() << std::endl;
							std::cout << std::string(indent, '\t') << "operatorID = " << (unsigned int)assign->assignmentOperator() << std::endl;
							Print(assign->expression(), indent);
							return;
						}

						case ExpressionType::BinaryOperation:
						{
							BinaryOperation* binary = (BinaryOperation*)expression;
							std::cout << std::string(indent, '\t') << "BinaryOperation:" << std::endl;
							indent++;
							Print(binary->left(), indent);
							std::cout << std::string(indent, '\t') << (unsigned int)binary->operation() << std::endl;
							Print(binary->right(), indent);
							return;
						}

						case ExpressionType::BooleanLiteral:
						{
							BooleanLiteral* boolLit = (BooleanLiteral*)expression;
							std::cout << std::string(indent, '\t') << "BoolLiteral:" << std::endl;
							indent++;
							std::cout << std::string(indent, '\t') << boolLit->value() << std::endl;
							return;
						}

						case ExpressionType::IdentifierExpression:
						{
							IdentifierExpression* id = (IdentifierExpression*)expression;
							std::cout << std::string(indent, '\t') << "IdExpression:" << std::endl;
							indent++;
							std::cout << std::string(indent, '\t') << id->identifier() << std::endl;
							return;
						}

						case ExpressionType::NumericLiteral:
						{
							NumericLiteral* num = (NumericLiteral*)expression;
							std::cout << std::string(indent, '\t') << "NumLiteral:" << std::endl;
							indent++;
							std::cout << std::string(indent, '\t') << (unsigned int)num->base() << std::endl;
							std::cout << std::string(indent, '\t') << (unsigned int)num->numeric_type() << std::endl;
							std::cout << std::string(indent, '\t') << num->text() << std::endl;
							return;
						}

						case ExpressionType::ParenthesesExpression:
						{
							ParenthesesExpression* parentheses = (ParenthesesExpression*)expression;
							std::cout << std::string(indent, '\t') << "ParenthesesExpression:" << std::endl;
							indent++;
							Print(parentheses->expression(), indent);
							return;
						}

						case ExpressionType::UnaryOperation:
						{
							UnaryOperation* unary = (UnaryOperation*)expression;
							std::cout << std::string(indent, '\t') << "UnaryOperation:" << std::endl;
							indent++;
							std::cout << std::string(indent, '\t') << (unsigned int)unary->operation() << std::endl;
							Print(unary->operand(), indent);
							return;
						}

						case ExpressionType::ConditionalDeclaration:
						{
							ConditionalDeclaration* decl = (ConditionalDeclaration*)expression;
							std::cout << std::string(indent, '\t') << "ConditionalDeclaration:" << std::endl;
							indent++;
							std::cout << std::string(indent, '\t') << decl->name() << std::endl;
							Print(decl->initializer(), indent);
						}

						default: return;
					}
				}

				void Print(const Yac::Syntax::Statement* statement, unsigned int indent = 0) noexcept
				{
					if (!statement) return;

					switch (statement->type())
					{

						case StatementType::None:
						{
							std::cout << "No Statement" << std::endl;
							return;
						}

						case StatementType::If:
						{
							IfStatement* If = (IfStatement*)statement;
							std::cout << std::string(indent, '\t') << "IfStatement: " << std::endl;
							indent++;
							Print(If->condition(), indent);
							Print(If->statement(), indent);
							const Statement* elseStatement = If->elseStatement();
							if (elseStatement) Print(elseStatement, indent);
							return;
						}

						case StatementType::VariableDeclaration:
						{
							VariableDeclaration* Decl = (VariableDeclaration*)statement;
							std::cout << std::string(indent, '\t') << "VarDecl: " << std::endl;
							indent++;
							std::cout << std::string(indent, '\t') << "name = " << Decl->name() << std::endl;
							Print(Decl->initializer(), indent);
							return;
						}

						case StatementType::While:
						{
							WhileStatement* While = (WhileStatement*)statement;
							std::cout << std::string(indent, '\t') << "WhileStatement: " << std::endl;
							indent++;
							Print(While->condition(), indent);
							Print(While->statement(), indent);
							return;
						}

						case StatementType::For:
						{
							ForStatement* For = (ForStatement*)statement;
							std::cout << std::string(indent, '\t') << "ForStatement: " << std::endl;
							indent++;
							Print(For->assignment(), indent);
							Print(For->condition(), indent);
							Print(For->update(), indent);
							Print(For->statement(), indent);
							return;
						}

						case StatementType::Block:
						{
							std::cout << std::string(indent, '\t') << "BlockStatement: " << std::endl;
							indent++;

							for (const Statement* statement : ((BlockStatement*)statement)->statements())
								Print(statement, indent);

							return;
						}

						case StatementType::Expression:
						{
							std::cout << std::string(indent, '\t') << "ExpressionStatement: " << std::endl;
							indent++;
							Print(((ExpressionStatement*)statement)->expression(), indent);
						}

						default: return;
					}
				}
			}
		}
	}
}

void AstPrinter::Print(const SyntaxTree& tree) noexcept { Print(tree.root()); }
void AstPrinter::Print(const SyntaxTree* tree) noexcept { Print(tree->root()); }


