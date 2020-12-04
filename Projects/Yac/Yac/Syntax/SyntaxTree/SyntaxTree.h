#pragma once

#include <string>

#include <Yac/Syntax/Statements/Statement.h>

#include <Yac/Errors/ErrorList.h>
#include <Yac/Text/SourceText.h>

namespace Yac::Syntax {

	class SyntaxTree final {

	public:

		SyntaxTree(const Yac::Text::SourceText& source, Yac::Errors::ErrorList& errorList);
		~SyntaxTree();

		const Statement* getRoot() const { return _root; }

	private:

		Statement* _root;
	};
}