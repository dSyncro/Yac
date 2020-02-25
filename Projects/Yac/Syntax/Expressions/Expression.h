#pragma once

#include "ExpressionType.h"

namespace Yac::Syntax {

	class Expression {

	public:

		virtual ~Expression() {}

		inline ExpressionType type() const noexcept { return _type; }
		static Expression* Null() noexcept;

	protected:

		Expression(ExpressionType type) : _type(type) {}
		ExpressionType _type = ExpressionType::None;

	};
}