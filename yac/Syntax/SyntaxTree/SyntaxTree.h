#pragma once

#include <string>

#include <yac/Syntax/Expressions/Expressions.h>
#include <yac/Syntax/Statements/Statement.h>

namespace Yac {
	namespace Syntax {

		class SyntaxTree {

		public:

			SyntaxTree(std::string& source);
			~SyntaxTree();

			inline const Statement* root() const { return _root; }

			void Print(const Expression* ptr = nullptr, unsigned int indent = 0) const noexcept;
			void Print(const Statement* ptr = nullptr, unsigned int indent = 0) const noexcept;

		private:

			Statement* _root;
		};

	}
}