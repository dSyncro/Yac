#pragma once

#include <string>

#include <Yac/Syntax/Expressions/Expressions.h>
#include <Yac/Syntax/Statements/Statement.h>

#include <Yac/Errors/ErrorList.h>
#include <Yac/Text/SourceText.h>

namespace Yac::Syntax {

	class SyntaxTree final {

	public:

		SyntaxTree(Yac::Text::SourceText source);
		SyntaxTree(Yac::Text::SourceText source, Yac::Errors::ErrorList& errorList);
		~SyntaxTree();

		inline const Statement* root() const { return _root; }

	private:

		Statement* _root;
	};
}