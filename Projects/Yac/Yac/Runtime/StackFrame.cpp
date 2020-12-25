#include "StackFrame.h"

#include "VirtualMemory.h"

#include <Yac/Core/Errors/Exceptions/NotConvertibleToException.h>
#include <Yac/Core/Errors/Exceptions/VariableAlreadyDeclearedException.h>
#include <Yac/Core/Errors/Exceptions/VariableNotDeclaredException.h>

using namespace Yac;
using namespace Yac::Core;
using namespace Yac::Errors;
using namespace Yac::Runtime;

StackFrame::StackFrame(Stack& stack) : _stack(&stack), _parent(nullptr), _location(0), _end(0) { }

StackFrame::StackFrame(StackFrame* parent)
	: _stack(parent->_stack), _location(parent->_stack->getOccupiedMemory()), _parent(parent), _end(0) { }

ByteT* StackFrame::getData() const noexcept { return _stack->getData() + _location; }

bool StackFrame::canPush() const noexcept { return &_stack->currentFrame() == this; }

bool StackFrame::isDeclared(const std::string& name) const noexcept
{
	auto it = _variables.find(name);
	return it != _variables.end();
}

void StackFrame::setVariable(const std::string& name, VariableData data)
{
	VariableData* variable = findVariable(name);

	if (variable == nullptr)
		throw VariableNotDeclaredException(name);
	
	if (variable->getType() != data.getType())
	{
		Cast cast(data.getType(), variable->getType());
		VirtualMemory& memory = _stack->virtualMemory();
		data = memory.conversionTable.convert(cast, memory.retrieve(data));
		if (data == VariableData::null()) throw NotConvertibleToException(cast);
	}

	*variable = data;
}

StackFrame* StackFrame::findVariableScope(const std::string& name)
{
	auto it = _variables.find(name);

	if (it != _variables.end())
		return this;

	if (!_parent)
		return nullptr;

	return _parent->findVariableScope(name);
}

VariableData* StackFrame::findVariable(const std::string& name)
{
	auto it = _variables.find(name);

	if (it != _variables.end())
		return &it->second;

	return nullptr;
}

VariableData StackFrame::findVariable(const std::string& name) const
{
	auto it = _variables.find(name);

	if (it != _variables.end())
		return it->second;

	return VariableData::null();
}

VariableData StackFrame::findInHierarchy(const std::string& name) const
{
	auto it = _variables.find(name);

	if (it != _variables.end())
		return it->second;

	if (!_parent)
		return VariableData::null();

	return _parent->findInHierarchy(name);
}

VariableData StackFrame::pushVariable(const std::string& name, VariableData data)
{
	auto it = _variables.find(name);

	if (it != _variables.end())
		throw VariableAlreadyDeclaredException(name);

	it->second = pushValue(data.getType(), data.isOnStack() ? _stack->retrieve(data) : data.getData());
	return it->second;
}

VariableData StackFrame::pushValue(const TypeSymbol& type, void* value)
{
	UIntT size = type.getSize();

	if (!_stack->canAllocate(size))
	{
		// throw error or resize
	}

	_stack->reserve(size);

	std::memcpy(_stack->getData() + getEndLocation(), value, size);
	VariableData out = VariableData(type, getEndLocation());
	_end += size;

	return out;
}