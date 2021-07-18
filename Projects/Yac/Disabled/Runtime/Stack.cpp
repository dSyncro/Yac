#include "Stack.h"
#include "StackFrame.h"

using namespace Yac;
using namespace Yac::Core;
using namespace Yac::Runtime;

Stack::Stack(VirtualMemory& virtualMemory) 
	: _virtualMemory(&virtualMemory), _occupied(0)
{
	_size = 1024 * 1024;
	_buffer = new ByteT[_size];
	_currentFrame = new StackFrame(*this);
}

Stack::~Stack()
{
	// Clear StackFrames
	StackFrame* nextFrame;
	do
	{
		nextFrame = _currentFrame->getParent();
		delete _currentFrame;
		_currentFrame = nextFrame;
	} while (nextFrame != nullptr);

	// Clear buffer
	delete[] _buffer;
}

const StackFrame& Stack::pushFrame() 
{ 
	_currentFrame = new StackFrame(_currentFrame);
	return *_currentFrame;
}

const StackFrame& Stack::popFrame()
{
	StackFrame* parent = _currentFrame->getParent();
	delete _currentFrame;
	_currentFrame = parent ? parent : new StackFrame(*this);
	return *_currentFrame;
}

void Stack::reserve(UIntT size) noexcept
{
	// Assert: should not overflow size
	_occupied += size;
}

VariableData Stack::pushVariable(const std::string& name, VariableData data)
{
	return _currentFrame->pushVariable(name, data);
}

VariableData Stack::pushValue(const TypeSymbol& type, void* value)
{
	return _currentFrame->pushValue(type, value);
}