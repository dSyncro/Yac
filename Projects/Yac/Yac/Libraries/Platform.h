#pragma once

#if defined(_WIN32) || defined(_WIN64)
#	define WINDOWS
#endif

#if defined(Linux32) || defined(Linux64)
#	define LINUX
#endif

#if defined(Mac32) || defined(Mac64)
#	define MACOS
#endif