#pragma once

#include "StatementType.h"

namespace Yac {
	namespace Syntax {

		class Statement {

		public:

			inline StatementType type() const noexcept { return _type; }
			static Statement* Null() noexcept;

			static void Dispose(Statement* expression);

		protected:

			Statement(StatementType type) : _type(type) {}
			StatementType _type = StatementType::None;

		};

	}
}