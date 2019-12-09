#pragma once

#include <string>
#include <yac/Syntax/Statements/Statement.h>

namespace Yac {
	namespace Syntax {

		class SyntaxTree {

		public:

			SyntaxTree(std::string& source);
			~SyntaxTree();

			inline const Statement* root() const { return _root; }

		private:

			Statement* _root;
		};

	}
}