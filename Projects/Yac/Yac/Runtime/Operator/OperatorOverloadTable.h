#pragma once

#include <functional>
#include <unordered_map>

#include <Yac/Core/Base.h>
#include <Yac/Core/Primitives.h>
#include <Yac/Runtime/VariableData.h>
#include <Yac/Runtime/Stack.h>
#include <Yac/Syntax/Operator.h>

#include "OperatorSymbol.h"

namespace Yac::Runtime {

    using UnaryOperatorHandler = FunctionHandler<VariableData, Stack&, const void*>;
    using BinaryOperatorHandler = FunctionHandler<VariableData, Stack&, const void*, const void*>;

    struct OperatorOverloadTable {

        OperatorOverloadTable(Stack& stack);

        bool exists(const Core::TypeSymbol& type) const;
        bool exists(const Core::TypeSymbol& firstType, const Core::TypeSymbol& secondType) const;

        bool isBound(const Core::TypeSymbol& type, Syntax::Operator op) const;
        bool isBound(const Core::TypeSymbol& firstType, const Core::TypeSymbol& secondType, Syntax::Operator op) const;

        UnaryOperatorHandler getHandler(const Core::TypeSymbol& type, Syntax::Operator op) const;
        BinaryOperatorHandler getHandler(const Core::TypeSymbol& firstType, const Core::TypeSymbol& secondType, Syntax::Operator op) const;

        void bind(const Core::TypeSymbol& type, Syntax::Operator op, UnaryOperatorHandler handler);
        void bind(const Core::TypeSymbol& firstType, const Core::TypeSymbol& secondType, Syntax::Operator op, BinaryOperatorHandler handler);

        VariableData call(const Core::TypeSymbol& type, const void* value, Syntax::Operator op);
        VariableData call(const Core::TypeSymbol& firstType, const Core::TypeSymbol& secondType, const void* firstValue, const void* secondValue, Syntax::Operator op);

        std::unordered_map<
            UnaryOperatorSymbol, 
            UnaryOperatorHandler[Syntax::getUnaryOperatorCount()]
        > _overloads;

        std::unordered_map<
            BinaryOperatorSymbol,
            BinaryOperatorHandler[Syntax::getBinaryOperatorCount()]
        > _binaryOverloads;

    private:

        Stack* _stack;
    };
}