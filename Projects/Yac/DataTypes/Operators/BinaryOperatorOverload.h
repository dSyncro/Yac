#pragma once

#include <DataTypes/Types/TypeSymbol.h>
#include <DataTypes/Variables/Data.h>

#include <Syntax/Expressions/Operations/Operator.h>

namespace Yac::DataTypes {

	using BinaryOperatorHandler = Data*(*)(Yac::Api::Object* first, Yac::Api::Object* second);

	struct BinaryOperatorOverload {

		BinaryOperatorOverload(Yac::Syntax::Operator operation, TypeSymbol first, TypeSymbol second, TypeSymbol returnType);

		Yac::Syntax::Operator Operation;
		TypeSymbol FirstOperandType;
		TypeSymbol SecondOperandType;
		TypeSymbol ReturnType;

        friend bool operator ==(const BinaryOperatorOverload& a, const BinaryOperatorOverload& b);
	};
}

namespace std {
    template<> struct hash<Yac::DataTypes::BinaryOperatorOverload>
    {
        std::size_t operator()(const Yac::DataTypes::BinaryOperatorOverload& overload) const noexcept
        {
            std::size_t h1 = std::hash<unsigned int>{}((unsigned int)overload.Operation);
            std::size_t h2 = std::hash<std::string>{}(overload.FirstOperandType.getName());
            std::size_t h3 = std::hash<std::string>{}(overload.SecondOperandType.getName());
            std::size_t h4 = std::hash<std::string>{}(overload.ReturnType.getName());
            return h1 ^ (h2 ^ (h3 ^ (h4 << 1)) << 1) << 1;
        }
    };
}