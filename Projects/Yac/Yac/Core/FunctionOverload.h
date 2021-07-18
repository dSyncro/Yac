#pragma once

#include "Types/TypeSymbol.h"
#include "ParameterSymbol.h"

#include <vector>

namespace Yac::Core {

	class FunctionOverload final {

	public:

		FunctionOverload(const TypeSymbol& returnType, const std::vector<ParameterSymbol>& parameters, Statement* functionStatement)
			: _retType(&returnType), _parameters(parameters), _funcStatement(functionStatement) { }

		const TypeSymbol& getReturnType() const noexcept { return *_retType; }
		const std::vector<ParameterSymbol>& getParameters() const noexcept { return _parameters; }
		Statement* getFunctionStatement() const noexcept { return _funcStatement; }

		bool operator ==(const FunctionOverload& other) const
		{
			return *_retType == other.getReturnType() && _parameters == other.getParameters();
		}

	private:

		const TypeSymbol* _retType;
		std::vector<ParameterSymbol> _parameters;
		Statement* _funcStatement;

	};

}