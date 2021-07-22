#pragma once

#include <Yac/Binding/Statements/BStatement.h>

namespace Yac {

	class BSyntaxTree final {

	public:

		BSyntaxTree(BStatement* root) 
			: _root(root) {}

		const BStatement* getRoot() const { return _root.get(); }

	private:

		std::shared_ptr<BStatement> _root;
	};
}