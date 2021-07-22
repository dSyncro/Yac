#pragma once

#include "StatementType.h"

namespace Yac {

	class Statement {

	public:

		Statement() : _type(StatementType::None) {}
		virtual ~Statement() = default;

		StatementType getType() const noexcept { return _type; }
		static Statement* Null() noexcept { return nullptr; }

	protected:

		Statement(StatementType type) : _type(type) {}
		StatementType _type;

	};
}