#pragma once

#include <Yac/Syntax/Expressions/ExpressionType.h>

namespace Yac {

	class BoundExpression {

	public:

		virtual ~BoundExpression() {}

		Syntax::ExpressionType getType() const noexcept { return _type; }

	protected:

		BoundExpression(Syntax::ExpressionType  type) : _type(type) {}
		Syntax::ExpressionType _type = Syntax::ExpressionType::None;

	};
}