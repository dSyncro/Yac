#pragma once

#include <Yac/Core/Types/TypeSymbol.h>
#include <Yac/Syntax/Expressions/ExpressionType.h>

namespace Yac {

	struct BExpression {

	public:

		virtual ~BExpression() {}

		const TypeSymbol& getType() const noexcept { return *_type; }
		ExpressionType getExpressionType() const noexcept { return _exprType; }

	protected:

		BExpression(ExpressionType expressionType, const TypeSymbol& type) 
			: _exprType(expressionType), _type(&type) {}

		ExpressionType _exprType;
		const TypeSymbol* _type;

	};
}