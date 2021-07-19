#pragma once

#include <Yac/Syntax/Expressions.h>
#include <Yac/Binding/BExpressions.h>

namespace Yac {

	class Binder {

	public:

		BExpression* bindExpression(const Expression* expression);

		BBinaryExpression* bindBinary(const BinaryOperationExpression* expression);
		BBooleanLiteralExpression* bindBooleanLiteral(const BooleanLiteralExpression* expression);
		BIdentifierExpression* bindIdentifier(const IdentifierExpression* expression);
		BStringLiteralExpression* bindStringLiteral(const StringLiteralExpression* expression);

	};

}