#pragma once

#include <DataTypes/Types/TypeSymbol.h>
#include <DataTypes/Variables/Data.h>

#include <Syntax/Expressions/Operations/Operator.h>

namespace Yac::DataTypes {

	using UnaryOperatorHandler = Data*(*)(Yac::Api::Object* operand);

	struct UnaryOperatorOverload {

		UnaryOperatorOverload(Yac::Syntax::Operator operation, TypeSymbol operandType, TypeSymbol returnType);

		Yac::Syntax::Operator Operation;
		TypeSymbol OperandType;
		TypeSymbol ReturnType;

        bool operator==(const UnaryOperatorOverload& other) const
        {
            return this == &other ||
                (this->Operation == other.Operation &&
                    this->OperandType == other.OperandType &&
                    this->ReturnType == other.ReturnType);
        }
	};
}

namespace std {
    template<> struct hash<Yac::DataTypes::UnaryOperatorOverload>
    {
        std::size_t operator()(const Yac::DataTypes::UnaryOperatorOverload& overload) const noexcept
        {
            std::size_t h1 = std::hash<unsigned int>{}((unsigned int)overload.Operation);
            std::size_t h2 = std::hash<std::string>{}(overload.OperandType.getName());
            std::size_t h3 = std::hash<std::string>{}(overload.ReturnType.getName());
            return h1 ^ (h2 ^ (h3 << 1)) << 1;
        }
    };
}