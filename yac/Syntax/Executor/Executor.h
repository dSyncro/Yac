#pragma once

#include <yac/Syntax/Expressions/Expression.h>

namespace Yac {
	namespace Syntax {

		class Executor {

		public:

			Executor(Expression* root);

		private:

			Expression* _root;

		};

	}
}