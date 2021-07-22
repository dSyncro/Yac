#pragma once

#include "SyntaxTree.h"

#include <Yac/Core/Errors/ErrorList.h>
#include <Yac/Core/Text/SourceText.h>

namespace Yac::Syntax {

	struct CompilationUnit {

	private:

		Errors::ErrorList _errors = Errors::ErrorList();

	public:

		CompilationUnit(const SourceText& source) : syntaxTree(source, _errors) {}

		SyntaxTree syntaxTree;

		const Errors::ErrorList& getErrors() const noexcept { return _errors; }
	};

}