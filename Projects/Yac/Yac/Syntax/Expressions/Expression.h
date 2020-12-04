#pragma once

#include "ExpressionType.h"

namespace Yac::Syntax {

	class Expression {

	public:

		virtual ~Expression() {}

		ExpressionType getType() const noexcept { return _type; }

	protected:

		Expression(ExpressionType type) : _type(type) {}
		ExpressionType _type = ExpressionType::None;

	};
}