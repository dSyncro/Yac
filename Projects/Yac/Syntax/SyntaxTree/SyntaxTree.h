#pragma once

#include <string>

#include <Syntax/Expressions/Expressions.h>
#include <Syntax/Statements/Statement.h>

#include <Errors/ErrorList.h>
#include <Text/SourceText.h>

namespace Yac::Syntax {

	class SyntaxTree final {

	public:

		SyntaxTree(Yac::Text::SourceText source, Yac::Errors::ErrorList& errorList);
		~SyntaxTree();

		inline const Statement* root() const { return _root; }

	private:

		Statement* _root;
	};
}