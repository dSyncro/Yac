#pragma once

#include <Yac/Core/Primitives.h>

#include <Yac/DataTypes/Types/TypeSymbol.h>
#include <Yac/DataTypes/Variables/Data.h>

#include <Yac/Syntax/Expressions/Operations/Operator.h>

namespace Yac::DataTypes {

	using BinaryOperatorHandler = Data*(*)(Yac::Api::Object* first, Yac::Api::Object* second);

	struct BinaryOperatorOverload {

		BinaryOperatorOverload(Yac::Syntax::Operator operation, TypeSymbol first, TypeSymbol second, TypeSymbol returnType);

		Yac::Syntax::Operator operation;
		TypeSymbol firstOperandType;
		TypeSymbol secondOperandType;
		TypeSymbol returnType;

        friend bool operator ==(const BinaryOperatorOverload& a, const BinaryOperatorOverload& b);
	};
}

namespace std {
    template<> struct hash<Yac::DataTypes::BinaryOperatorOverload>
    {
        std::size_t operator()(const Yac::DataTypes::BinaryOperatorOverload& overload) const noexcept
        {
            std::size_t h1 = std::hash<Yac::UIntT>{}((Yac::UIntT)overload.operation);
            std::size_t h2 = std::hash<std::string>{}(overload.firstOperandType.getName());
            std::size_t h3 = std::hash<std::string>{}(overload.secondOperandType.getName());
            std::size_t h4 = std::hash<std::string>{}(overload.returnType.getName());
            return h1 ^ (h2 ^ (h3 ^ (h4 << 1)) << 1) << 1;
        }
    };
}