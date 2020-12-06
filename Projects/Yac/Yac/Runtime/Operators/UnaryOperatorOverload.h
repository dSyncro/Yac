#pragma once

#include <Yac/Core/Primitives.h>
#include <Yac/Core/Types/TypeSymbol.h>
#include <Yac/Syntax/Operator.h>

namespace Yac::Runtime {

	using UnaryOperatorHandler = VariableData(*)(Yac::Api::Object* operand);

	struct UnaryOperatorOverload {

		UnaryOperatorOverload(Yac::Syntax::Operator operation, const Core::TypeSymbol& operandType, const Core::TypeSymbol& returnType) 
            : operation(operation), operandType(operandType), returnType(returnType) { }

		Syntax::Operator operation;
        const Core::TypeSymbol& operandType;
        const Core::TypeSymbol& returnType;

        bool operator ==(const UnaryOperatorOverload& other) const
        {
            return this == &other ||
                (this->operation == other.operation &&
                    this->operandType == other.operandType &&
                    this->returnType == other.returnType);
        }
	};
}

namespace std {
    template<> struct hash<Yac::Runtime::UnaryOperatorOverload>
    {
        std::size_t operator()(const Yac::Runtime::UnaryOperatorOverload& overload) const noexcept
        {
            std::size_t h1 = std::hash<Yac::UIntT>{}((Yac::UIntT)overload.operation);
            std::size_t h2 = std::hash<std::string>{}(overload.operandType.getName());
            std::size_t h3 = std::hash<std::string>{}(overload.returnType.getName());
            return h1 ^ (h2 ^ (h3 << 1)) << 1;
        }
    };
}