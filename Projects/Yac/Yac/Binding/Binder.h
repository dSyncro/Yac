#pragma once

#include <Yac/Syntax/Expressions.h>
#include <Yac/Binding/BExpressions.h>

namespace Yac {

	class Binder {

	public:

		BExpression* bindExpression(const Expression* expression);

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

	};

}