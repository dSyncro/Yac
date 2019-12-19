#pragma once

#include "SyntaxTree.h"

#include <iostream>

namespace Yac {
	namespace Syntax {
		namespace AstPrinter
		{
			void Print(const SyntaxTree& tree) noexcept;
			void Print(const SyntaxTree* tree) noexcept;
		};
	}
}