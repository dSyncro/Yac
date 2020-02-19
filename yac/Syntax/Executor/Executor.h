#pragma once

#include <yac/Syntax/SyntaxTree/SyntaxTree.h>

namespace Yac::Syntax {

	class Executor {

	public:

		Executor(const SyntaxTree& tree);

		int Execute();

	private:

		int EvaluateExpressionStatement();

		const Statement* _root;

	};
}