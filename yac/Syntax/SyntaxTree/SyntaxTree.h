#pragma once

#include <string>

#include <yac/Syntax/Expressions/Expressions.h>
#include <yac/Syntax/Statements/Statement.h>

#include <yac/Text/SourceText.h>

namespace Yac {
	namespace Syntax {

		class SyntaxTree {

		public:

			SyntaxTree(Yac::Text::SourceText source);
			~SyntaxTree();

			inline const Statement* root() const { return _root; }

		private:

			Statement* _root;
		};

	}
}