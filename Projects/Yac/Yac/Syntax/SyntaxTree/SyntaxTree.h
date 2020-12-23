#pragma once

#include <string>
#include <memory>

#include <Yac/Syntax/Statements/Statement.h>

#include <Yac/Core/Errors/ErrorList.h>
#include <Yac/Core/Text/SourceText.h>

namespace Yac::Syntax {

	class SyntaxTree final {

	public:

		SyntaxTree(const Core::SourceText& source, Errors::ErrorList& errorList);

		const Statement* getRoot() const { return _root.get(); }

	private:

		std::shared_ptr<Statement> _root;
	};
}