#pragma once

#include <Yac/Core/Primitives.h>
#include <Yac/Core/Types/TypeSymbol.h>
#include <Yac/Runtime/VariableData.h>
#include <Yac/Syntax/Operator.h>

namespace Yac::Runtime {

	using BinaryOperatorHandler = VariableData(*)(Api::Object* first, Api::Object* second);

	struct BinaryOperatorOverload {

		BinaryOperatorOverload(Syntax::Operator operation, const Core::TypeSymbol& first, const Core::TypeSymbol& second, const Core::TypeSymbol& returnType)
            : operation(operation), firstOperandType(first), secondOperandType(second), returnType(returnType) { }

		Syntax::Operator operation;
		Core::TypeSymbol firstOperandType;
		Core::TypeSymbol secondOperandType;
		Core::TypeSymbol returnType;

        bool operator ==(const BinaryOperatorOverload& other) const 
        {
            return this == &other ||
                (operation == other.operation &&
                    firstOperandType == other.firstOperandType &&
                    secondOperandType == other.secondOperandType &&
                    returnType == other.returnType);
        }
	};
}

namespace std {
    template<> struct hash<Yac::Runtime::BinaryOperatorOverload>
    {
        std::size_t operator()(const Yac::Runtime::BinaryOperatorOverload& overload) const noexcept
        {
            std::size_t h1 = std::hash<Yac::UIntT>{}((Yac::UIntT)overload.operation);
            std::size_t h2 = std::hash<std::string>{}(overload.firstOperandType.getName());
            std::size_t h3 = std::hash<std::string>{}(overload.secondOperandType.getName());
            std::size_t h4 = std::hash<std::string>{}(overload.returnType.getName());
            return h1 ^ (h2 ^ (h3 ^ (h4 << 1)) << 1) << 1;
        }
    };
}