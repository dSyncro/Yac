#pragma once

#include <Yac/Binding/BBinaryOperator.h>

namespace Yac {

	class BinaryOperatorTable final {

	public:

		DeclarationResult declare(const BBinaryOperator& op);

		bool exists(const BBinarySignature& signature) const;
		const TypeSymbol& getReturnType(const BBinarySignature& signature) const;

	private:

		std::unordered_map<BBinarySignature, const TypeSymbol*> _operators;
	};
}