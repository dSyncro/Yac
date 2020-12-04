#pragma once

#include <Yac/Core/Primitives.h>

#include <Yac/DataTypes/Types/TypeSymbol.h>
#include <Yac/DataTypes/Variables/Data.h>

#include <Yac/Syntax/Expressions/Operations/Operator.h>

namespace Yac::DataTypes {

	using UnaryOperatorHandler = Data*(*)(Yac::Api::Object* operand);

	struct UnaryOperatorOverload {

		UnaryOperatorOverload(Yac::Syntax::Operator operation, TypeSymbol operandType, TypeSymbol returnType);

		Yac::Syntax::Operator operation;
		TypeSymbol operandType;
		TypeSymbol returnType;

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
    template<> struct hash<Yac::DataTypes::UnaryOperatorOverload>
    {
        std::size_t operator()(const Yac::DataTypes::UnaryOperatorOverload& overload) const noexcept
        {
            std::size_t h1 = std::hash<Yac::UIntT>{}((Yac::UIntT)overload.operation);
            std::size_t h2 = std::hash<std::string>{}(overload.operandType.getName());
            std::size_t h3 = std::hash<std::string>{}(overload.returnType.getName());
            return h1 ^ (h2 ^ (h3 << 1)) << 1;
        }
    };
}