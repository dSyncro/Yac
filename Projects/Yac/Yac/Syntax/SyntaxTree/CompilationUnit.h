#pragma once

#include "SyntaxTree.h"

#include <Yac/Errors/ErrorList.h>
#include <Yac/Text/SourceText.h>

namespace Yac::Syntax {

	struct CompilationUnit {

	private:

		Errors::ErrorList _errors = Errors::ErrorList();

	public:

		CompilationUnit(const Yac::Text::SourceText& source) : syntaxTree(source, _errors) {}

		SyntaxTree syntaxTree;

		const Errors::ErrorList& getErrors() const noexcept { return _errors; }
	};

}