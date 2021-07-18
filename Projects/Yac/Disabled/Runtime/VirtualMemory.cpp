#include "VirtualMemory.h"

#include "Stack.h"

using namespace Yac;
using namespace Yac::Core;
using namespace Yac::Runtime;

VirtualMemory::VirtualMemory() :
	stack(*this),
	conversionTable(ConversionTable(stack)),
	operatorTable(OperatorOverloadTable(stack))
{
}

void* VirtualMemory::retrieve(VariableData data)
{
	if (data.isOnStack())
		return stack.retrieve(data);
	else return data.getData();
}

ByteT* VirtualMemory::allocate(const Core::TypeSymbol& type) const noexcept
{
	ByteT* buffer = new ByteT[type.getSize()];
	return buffer;
}