#pragma once

#include "SyntaxTree.h"

#include <Libraries/AnsiStyle/AnsiStyle.h>

#include <iostream>

namespace Yac::Syntax::AstPrinter {

	struct FormattingOptions {
		AnsiStyle::Forecolors DecoratorsColor = AnsiStyle::Forecolors::White;
		AnsiStyle::Forecolors StatementColor = AnsiStyle::Forecolors::Cyan;
		AnsiStyle::Forecolors ExpressionColor = AnsiStyle::Forecolors::Yellow;
		AnsiStyle::Forecolors DataColor = AnsiStyle::Forecolors::White;
		AnsiStyle::Forecolors LabelColor = AnsiStyle::Forecolors::Green;
	};

	extern FormattingOptions formattingOptions;

	void Print(const SyntaxTree& tree) noexcept;
	void Print(const SyntaxTree* tree) noexcept;

}