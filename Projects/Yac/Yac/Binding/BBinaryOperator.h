#pragma once

#include <vector>

#include <Yac/Syntax/Operator.h>
#include <Yac/Core/Types/TypeTable.h>
#include <Yac/Binding/BBinarySignature.h>

namespace Yac {

	struct BBinaryOperator {

		BBinaryOperator(const BBinarySignature& signature, const TypeSymbol& returnType)
			: _signature(signature), _returnType(&returnType) {}

		const BBinarySignature& getSignature() const noexcept { return _signature; }
		const TypeSymbol& getReturnType() const noexcept { return *_returnType; }

	private:

		BBinarySignature _signature;
		const TypeSymbol* _returnType;

	};
}