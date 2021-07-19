#pragma once

#include "ExpressionType.h"

namespace Yac {

	class Expression {

	public:

		virtual ~Expression() {}

		ExpressionType getType() const noexcept { return _type; }

		static Expression* null() noexcept { return nullptr; }

	protected:

		Expression(ExpressionType type) : _type(type) {}
		ExpressionType _type = ExpressionType::None;

	};
}