#pragma once

#include <Yac/Core/Types/TypeSymbol.h>

namespace Yac::Runtime {

    struct UnaryOperatorSymbol {

        UnaryOperatorSymbol(const Core::TypeSymbol& operandType) : _operand(&operandType) {}

        const Core::TypeSymbol& getOperandType() const noexcept { return *_operand; }

        bool operator ==(const UnaryOperatorSymbol& other) const { return *_operand == other.getOperandType(); }

    private:

        const Core::TypeSymbol* _operand;
    };

    struct BinaryOperatorSymbol {

        BinaryOperatorSymbol(const Core::TypeSymbol& left, const Core::TypeSymbol& right)
            : _left(&left), _right(&right) { }

        const Core::TypeSymbol& getLeftType() const noexcept { return *_left; }
        const Core::TypeSymbol& getRightType() const noexcept { return *_right; }

        bool operator ==(const BinaryOperatorSymbol& other) const { return *_left == other.getLeftType() && *_right == other.getRightType(); }

    private:

        const Core::TypeSymbol* _left;
        const Core::TypeSymbol* _right;
    };

}

namespace std {

    template <>
    struct hash<Yac::Runtime::UnaryOperatorSymbol>
    {
        std::size_t operator()(const Yac::Runtime::UnaryOperatorSymbol& b) const
        {
            return std::hash<const Yac::Core::TypeSymbol*>()(&b.getOperandType());
        }
    };

    template <>
    struct hash<Yac::Runtime::BinaryOperatorSymbol>
    {
        std::size_t operator()(const Yac::Runtime::BinaryOperatorSymbol& b) const
        {
            return std::hash<const Yac::Core::TypeSymbol*>()(&b.getLeftType()) ^
                (std::hash<const Yac::Core::TypeSymbol*>()(&b.getRightType()) << 1);
        }
    };
}