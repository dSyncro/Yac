#pragma once

#if defined(Win32) || defined(Win64)
#	define WINDOWS
#endif

#if defined(Linux32) || defined(Linux64)
#	define LINUX
#endif