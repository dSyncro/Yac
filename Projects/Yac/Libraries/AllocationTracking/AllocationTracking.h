#pragma once

#include <Libraries/Platform.h>

extern void* operator new(size_t size, char* file, std::size_t line, char* function);

extern void operator delete(void* ptr);
extern void operator delete(void* ptr, char* file, std::size_t line, char* function);

#ifdef WINDOWS
#	define __FUNC__ __FUNCTION__
#else
#	define __FUNC__ __func__
#endif

#ifdef YAC_DEBUG
#	define NEW new((char*)__FILE__, __LINE__, __FUNC__)
#	define DEL delete((char*)__FILE__, __LINE__, __FUNC__)
#else
#	define NEW new
#	define DEL delete
#endif

namespace AllocationTracking {

	struct AllocationInfo {
		void* Address;
		std::size_t Size;
		char* Filename;
		std::size_t Line;
		char* FunctionName;
	};

}