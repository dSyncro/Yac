#pragma once

#include <Yac/Binding/Expressions/BExpression.h>
#include <Yac/Binding/Scopes/Scope.h>
#include <Yac/Core/Numeric.h>
#include <Yac/Core/NumericType.h>

namespace Yac {

	struct BNumericLiteralExpression final : BExpression {
		BNumericLiteralExpression(Numeric numeric, NumericType type, Scope* scope)
			: BExpression(ExpressionType::NumericLiteral, TypeSymbol::getInvalidTypeSymbol()),
			number(numeric), numericType(type)
		{
			switch (type)
			{
				case NumericType::Int:
					_type = &scope->findTypeByName("int");
					break;
				case NumericType::UInt:
					_type = &scope->findTypeByName("uint");
					break;
				case NumericType::Float:
					_type = &scope->findTypeByName("float");
					break;
				case NumericType::Double:
					_type = &scope->findTypeByName("double");
					break;
			}
		}

		Numeric number;
		NumericType numericType;
	};
}