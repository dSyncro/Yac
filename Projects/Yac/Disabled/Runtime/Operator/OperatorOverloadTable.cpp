#include "OperatorOverloadTable.h"

#include <Yac/Core/Errors/Exceptions/NoOperatorOverloadException.h>

using namespace Yac;
using namespace Yac::Core;
using namespace Yac::Errors;
using namespace Yac::Runtime;
using namespace Yac::Syntax;

static VariableData boolAndOperator(Stack& stack, const void* left, const void* right)
{
    bool a = *reinterpret_cast<const bool*>(left);
    bool b = *reinterpret_cast<const bool*>(right);
    bool result = a && b;
    return stack.pushValue(TypeSymbol::getBoolTypeSymbol(), &result);
}

static VariableData boolOrOperator(Stack& stack, const void* left, const void* right)
{
    bool a = *reinterpret_cast<const bool*>(left);
    bool b = *reinterpret_cast<const bool*>(right);
    bool result = a || b;
    return stack.pushValue(TypeSymbol::getBoolTypeSymbol(), &result);
}

static VariableData intAdditionOperator(Stack& stack, const void* left, const void* right)
{
    IntT a = *reinterpret_cast<const IntT*>(left);
    IntT b = *reinterpret_cast<const IntT*>(right);
    IntT result = a + b;
    return stack.pushValue(TypeSymbol::getIntTypeSymbol(), &result);
}

static VariableData intSubtractionOperator(Stack& stack, const void* left, const void* right)
{
    IntT a = *reinterpret_cast<const IntT*>(left);
    IntT b = *reinterpret_cast<const IntT*>(right);
    IntT result = a - b;
    return stack.pushValue(TypeSymbol::getIntTypeSymbol(), &result);
}

static VariableData intMultiplicationOperator(Stack& stack, const void* left, const void* right)
{
    IntT a = *reinterpret_cast<const IntT*>(left);
    IntT b = *reinterpret_cast<const IntT*>(right);
    IntT result = a * b;
    return stack.pushValue(TypeSymbol::getIntTypeSymbol(), &result);
}

static VariableData intDivisionOperator(Stack& stack, const void* left, const void* right)
{
    IntT a = *reinterpret_cast<const IntT*>(left);
    IntT b = *reinterpret_cast<const IntT*>(right);
    IntT result = a / b;
    return stack.pushValue(TypeSymbol::getIntTypeSymbol(), &result);
}

OperatorOverloadTable::OperatorOverloadTable(Stack& stack)
    : _stack(&stack)
{
    bind(TypeSymbol::getBoolTypeSymbol(), TypeSymbol::getBoolTypeSymbol(), Operator::LogicalAnd, boolAndOperator);
    bind(TypeSymbol::getBoolTypeSymbol(), TypeSymbol::getBoolTypeSymbol(), Operator::LogicalOr, boolOrOperator);
    bind(TypeSymbol::getIntTypeSymbol(), TypeSymbol::getIntTypeSymbol(), Operator::Addition, intAdditionOperator);
    bind(TypeSymbol::getIntTypeSymbol(), TypeSymbol::getIntTypeSymbol(), Operator::Subtraction, intSubtractionOperator);
    bind(TypeSymbol::getIntTypeSymbol(), TypeSymbol::getIntTypeSymbol(), Operator::Multiplication, intMultiplicationOperator);
    bind(TypeSymbol::getIntTypeSymbol(), TypeSymbol::getIntTypeSymbol(), Operator::Division, intDivisionOperator);
}

bool OperatorOverloadTable::exists(const TypeSymbol& type) const
{
    UnaryOperatorSymbol id = UnaryOperatorSymbol(type);
    auto it = _overloads.find(id);
    return it != _overloads.end();
}

bool OperatorOverloadTable::exists(const TypeSymbol& firstType, const TypeSymbol& secondType) const
{
    BinaryOperatorSymbol id = BinaryOperatorSymbol(firstType, secondType);
    auto it = _binaryOverloads.find(id);
    return it != _binaryOverloads.end();
}

bool OperatorOverloadTable::isBound(const TypeSymbol& type, Operator op) const
{
    UnaryOperatorSymbol id = UnaryOperatorSymbol(type);
    auto it = _overloads.find(id);

    if (it == _overloads.end()) return false;

    return it->second[(UIntT)op] != nullptr;
}

bool OperatorOverloadTable::isBound(const TypeSymbol& firstType, const TypeSymbol& secondType, Operator op) const
{
    BinaryOperatorSymbol id = BinaryOperatorSymbol(firstType, secondType);
    auto it = _binaryOverloads.find(id);

    if (it == _binaryOverloads.end()) return false;

    return it->second[(UIntT)op] != nullptr;
}

UnaryOperatorHandler OperatorOverloadTable::getHandler(const TypeSymbol& type, Operator op) const
{
    UnaryOperatorSymbol id = UnaryOperatorSymbol(type);
    auto it = _overloads.find(id);
    return it != _overloads.end() ? it->second[(UIntT)op] : nullptr;
}

BinaryOperatorHandler OperatorOverloadTable::getHandler(const TypeSymbol& firstType, const TypeSymbol& secondType, Operator op) const
{
    BinaryOperatorSymbol id = BinaryOperatorSymbol(firstType, secondType);
    auto it = _binaryOverloads.find(id);

    return it != _binaryOverloads.end() ? it->second[(UIntT)op - getUnaryOperatorCount()] : nullptr;
}

void OperatorOverloadTable::bind(const TypeSymbol& type, Operator op, UnaryOperatorHandler handler)
{
    UnaryOperatorSymbol id = UnaryOperatorSymbol(type);
    _overloads[id][(UIntT)op] = handler;
}

void OperatorOverloadTable::bind(const TypeSymbol& firstType, const TypeSymbol& secondType, Operator op, BinaryOperatorHandler handler)
{
    BinaryOperatorSymbol id = BinaryOperatorSymbol(firstType, secondType);
    _binaryOverloads[id][(UIntT)op - getUnaryOperatorCount()] = handler;
}

VariableData OperatorOverloadTable::call(const Core::TypeSymbol& type, const void* value, Operator op)
{
    UnaryOperatorHandler handler = getHandler(type, op);
    if (handler == nullptr)
        throw NoUnaryOperatorOverloadException(type, op);

    return handler(*_stack, value);
}

VariableData OperatorOverloadTable::call(const TypeSymbol& firstType, const TypeSymbol& secondType, const void* firstValue, const void* secondValue, Operator op)
{
    BinaryOperatorHandler handler = getHandler(firstType, secondType, op);
    if (handler == nullptr)
        throw NoBinaryOperatorOverloadException(firstType, secondType, op);

    return handler(*_stack, firstValue, secondValue);
}