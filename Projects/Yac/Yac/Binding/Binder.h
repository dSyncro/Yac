#pragma once

#include <Yac/Syntax/Expressions.h>
#include <Yac/Syntax/Statements.h>
#include <Yac/Binding/BExpressions.h>
#include <Yac/Binding/BStatements.h>
#include <Yac/Binding/BSyntaxTree.h>
#include <Yac/Syntax/SyntaxTree/SyntaxTree.h>

namespace Yac {

	class Binder {

	public:

		Binder();
		~Binder();

		BSyntaxTree bind(const SyntaxTree& tree);

		NamespaceScope* getGlobalScope() const noexcept { return _globalScope; }

	private:

		BStatement* bindStatement(const Statement* statement);
		BExpression* bindExpression(const Expression* expression);

		BStatement* bindBlockStatement(const BlockStatement* statement);
		BStatement* bindExpressionStatement(const ExpressionStatement* statement);
		BStatement* bindForStatement(const ForStatement* statement);
		BStatement* bindIfStatement(const IfStatement* statement);
		BStatement* bindVarDeclStatement(const VariableDeclarationStatement* statement);
		BStatement* bindWhileStatement(const WhileStatement* statement);

		BAssignmentExpression* bindAssignment(const AssignmentExpression* expression);
		BBinaryExpression* bindBinary(const BinaryOperationExpression* expression);
		BBooleanLiteralExpression* bindBooleanLiteral(const BooleanLiteralExpression* expression);
		BConditionalDeclExpression* bindConditionalDeclaration(const ConditionalDeclarationExpression* expression);
		BIdentifierExpression* bindIdentifier(const IdentifierExpression* expression);
		BInlineIfElse* bindInlineIfElse(const InlineIfElseExpression* expression);
		BNumericLiteralExpression* bindNumericLiteral(const NumericLiteralExpression* expression);
		BParenthesesExpression* bindParentheses(const ParenthesesExpression* expression);
		BStringLiteralExpression* bindStringLiteral(const StringLiteralExpression* expression);
		BUnaryExpression* bindUnary(const UnaryOperationExpression* expression);

		Scope* _currentScope;
		NamespaceScope* _globalScope;

	};

}