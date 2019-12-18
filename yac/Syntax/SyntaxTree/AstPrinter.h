#pragma once

#include "SyntaxTree.h"

#include <iostream>

namespace Yac {
	namespace Syntax {

		class AstPrinter
		{

		public:

			static void Print(const SyntaxTree& tree) noexcept;
			static void Print(const SyntaxTree* tree) noexcept;

		private:

			AstPrinter() {}

			static void Print(const Yac::Syntax::Expression* ptr, unsigned int indent = 0) noexcept;
			static void Print(const Yac::Syntax::Statement* ptr, unsigned int indent = 0) noexcept;
		};

	}
}