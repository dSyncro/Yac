#pragma once

#include "StatementType.h"

namespace Yac {
	namespace Syntax {

		class Statement {

		public:

			Statement() : _type(StatementType::None) {}
			~Statement() { Statement::Dispose(this); }

			inline StatementType type() const noexcept { return _type; }
			static Statement* Null() noexcept;

			static void Dispose(Statement* expression);

		protected:

			Statement(StatementType type) : _type(type) {}
			StatementType _type;

		};

	}
}