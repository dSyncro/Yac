#pragma once

#include "Bound.h"
#include "BoundExpression.h"

#include <Yac/Core/Types/TypeTable.h>
#include <Yac/Syntax/Expressions/StringExpression.h>

namespace Yac {

	struct BoundStringExpression final : BoundExpression {

	public:

		BoundStringExpression(const Syntax::StringExpression& expression)
			: BoundExpression(Syntax::ExpressionType::String), 
			_boundText(expression.getText(), getGlobalTypeTable().get("string")) { }

		const std::string& getText() const noexcept { return _boundText.getValue(); }
		const TypeSymbol& getType() const noexcept { return _boundText.getType(); }

	private:

		Bound<std::string> _boundText;
	};
}