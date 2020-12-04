#pragma once

#include "StatementType.h"

namespace Yac::Syntax {

	class Statement {

	public:

		Statement() : _type(StatementType::None) {}
		virtual ~Statement() {}

		StatementType getType() const noexcept { return _type; }
		static Statement* Null() noexcept;

	protected:

		Statement(StatementType type) : _type(type) {}
		StatementType _type;

	};
}