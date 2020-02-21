#pragma once

#include "SyntaxTree.h"

#include <Yac/Errors/ErrorList.h>
#include <Yac/Text/SourceText.h>

namespace Yac::Syntax {

	struct CompilationUnit {

	private:

		Errors::ErrorList _errors = Yac::Errors::ErrorList();

	public:

		CompilationUnit(Yac::Text::SourceText source) : Tree(source, _errors) {}

		SyntaxTree Tree;

		inline const Errors::ErrorList& errors() const noexcept { return _errors; }
	};

}