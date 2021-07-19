#pragma once

#include <Yac/Binding/Expressions/BExpression.h>
#include <Yac/Core/Numeric.h>
#include <Yac/Core/NumericType.h>
#include <Yac/Core/Namespace.h>

namespace Yac {

	struct BNumericLiteralExpression final : BExpression {
		BNumericLiteralExpression(Numeric numeric, NumericType type)
			: BExpression(ExpressionType::NumericLiteral, TypeSymbol::getInvalidTypeSymbol()),
			number(numeric), numericType(type)
		{
			switch (type)
			{
				case NumericType::Int:
					_type = &Namespace::getGlobalTypeTable().get("int");
					break;
				case NumericType::UInt:
					_type = &Namespace::getGlobalTypeTable().get("uint");
					break;
				case NumericType::Float:
					_type = &Namespace::getGlobalTypeTable().get("float");
					break;
				case NumericType::Double:
					_type = &Namespace::getGlobalTypeTable().get("double");
					break;
			}
		}

		Numeric number;
		NumericType numericType;
	};
}