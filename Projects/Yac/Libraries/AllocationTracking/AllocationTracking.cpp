#include <vector>

#include "AllocationTracking.h"

#include <Libraries/Console/Console.h>

using namespace AllocationTracking;

std::vector<AllocationInfo> allocations;

void* operator new(size_t size, char* file, std::size_t line, char* function)
{
	void* ptr = malloc(size);
	if (!ptr) throw std::bad_alloc();

	Console::WriteColored(AnsiStyle::Forecolors::Yellow, file, " (", line, ") -> ", function, ": ");
	Console::WriteColoredLine(AnsiStyle::Forecolors::White, "Allocated ", size, " bytes");

	AllocationInfo track = { ptr, size, file, line, function };
	allocations.push_back(track);

	return ptr;
}

void operator delete(void* ptr)
{
	std::vector<AllocationInfo>::const_iterator it;

	if (!allocations.size() == 0)
	{
		for (it = allocations.begin(); it != allocations.end(); it++)
		{
			if (it->Address != ptr) continue;

			Console::WriteColored(AnsiStyle::Forecolors::Yellow, it->Filename, " (", it->Line, ") -> ", it->FunctionName, ": ");
			Console::WriteColoredLine(AnsiStyle::Forecolors::White, "Freed ", it->Size, " bytes");

			allocations.erase(it);
			break;
		}
	}

	free(ptr);
}

void operator delete(void* ptr, char* file, std::size_t line, char* function)
{
	std::vector<AllocationInfo>::const_iterator it;

	if (!allocations.size() == 0) {
		for (it = allocations.begin(); it != allocations.end(); it++)
		{
			if (it->Address != ptr) continue;

			Console::WriteColored(AnsiStyle::Forecolors::Yellow, file, " (", line, ") -> " , function, ": ");
			Console::WriteColoredLine(AnsiStyle::Forecolors::White, "Freed ", it->Size, " bytes");

			allocations.erase(it);
			break;
		}
	}
	
	free(ptr);
}

void PrintAllocationTable()
{
	Console::WriteColoredLine(AnsiStyle::Forecolors::Green, "AllocationTable = {");
	for (const AllocationInfo& info : allocations)
	{
		Console::Write("\t");
		Console::WriteColoredLine(AnsiStyle::Forecolors::Cyan, info.Address, ": ");
		Console::Write("\t\t");
		Console::WriteColoredLine(AnsiStyle::Forecolors::Magenta, "Size = ", info.Size);
		Console::Write("\t\t");
		Console::WriteColoredLine(AnsiStyle::Forecolors::Yellow, "Declared in ", info.Filename, " (", info.Size, ")");
		Console::Write("\t\t");
		Console::WriteColoredLine(AnsiStyle::Forecolors::Yellow, "In Function ", info.FunctionName);
	}
	Console::WriteColoredLine(AnsiStyle::Forecolors::Green, "}");
}