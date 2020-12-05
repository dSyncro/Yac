#pragma once

#include <string>

#include <Yac/Syntax/Statements/Statement.h>

#include <Yac/Core/Errors/ErrorList.h>
#include <Yac/Core/Text/SourceText.h>

namespace Yac::Syntax {

	class SyntaxTree final {

	public:

		SyntaxTree(const Text::SourceText& source, Errors::ErrorList& errorList);
		~SyntaxTree();

		const Statement* getRoot() const { return _root; }

	private:

		Statement* _root;
	};
}