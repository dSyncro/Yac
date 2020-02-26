#pragma once

#if defined Win32 || defined Win64
#	include <Windows.h>
#endif

#include "Libraries/AnsiStyle/AnsiStyle.h"

namespace Console {

	// Win specific functions
	namespace {

		const HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

		inline CONSOLE_SCREEN_BUFFER_INFO GetConsoleInfo() noexcept
		{
			CONSOLE_SCREEN_BUFFER_INFO info;
			GetConsoleScreenBufferInfo(hConsole, &info);
			return info;
		}

		const CONSOLE_SCREEN_BUFFER_INFO baseConsoleInfo = GetConsoleInfo();

		enum class WinConsoleColors {
			Black,
			Blue,
			Green,
			Aqua,
			Red,
			Purple,
			Yellow,
			White,
			Gray,
			LightBlue,
			LightGreen,
			LightAqua,
			LightRed,
			LightPurple,
			LightYellow,
			BrightWhite
		};

		void SetWinForegroundColor(AnsiStyle::Forecolors color)
		{
			WinConsoleColors consoleColor = WinConsoleColors::White;

			switch (color)
			{
				case AnsiStyle::Forecolors::Dark_Black:
					consoleColor = WinConsoleColors::Black;
					break;
				case AnsiStyle::Forecolors::Dark_Red:
					consoleColor = WinConsoleColors::Red;
					break;
				case AnsiStyle::Forecolors::Dark_Green:
					consoleColor = WinConsoleColors::Green;
					break;
				case AnsiStyle::Forecolors::Dark_Yellow:
					consoleColor = WinConsoleColors::Yellow;
					break;
				case AnsiStyle::Forecolors::Dark_Blue:
					consoleColor = WinConsoleColors::Blue;
					break;
				case AnsiStyle::Forecolors::Dark_Magenta:
					consoleColor = WinConsoleColors::Purple;
					break;
				case AnsiStyle::Forecolors::Dark_Cyan:
					consoleColor = WinConsoleColors::Aqua;
					break;
				case AnsiStyle::Forecolors::Dark_White:
					consoleColor = WinConsoleColors::White;
					break;
				case AnsiStyle::Forecolors::Black:
					consoleColor = WinConsoleColors::Gray;
					break;
				case AnsiStyle::Forecolors::Red:
					consoleColor = WinConsoleColors::LightRed;
					break;
				case AnsiStyle::Forecolors::Green:
					consoleColor = WinConsoleColors::LightGreen;
					break;
				case AnsiStyle::Forecolors::Yellow:
					consoleColor = WinConsoleColors::LightYellow;
					break;
				case AnsiStyle::Forecolors::Blue:
					consoleColor = WinConsoleColors::LightBlue;
					break;
				case AnsiStyle::Forecolors::Magenta:
					consoleColor = WinConsoleColors::LightPurple;
					break;
				case AnsiStyle::Forecolors::Cyan:
					consoleColor = WinConsoleColors::LightAqua;
					break;
				case AnsiStyle::Forecolors::White:
					consoleColor = WinConsoleColors::BrightWhite;
					break;
				default: break;
			}

			SetConsoleTextAttribute(hConsole, (int)consoleColor);
		}

		void SetWinBackgroundColor(AnsiStyle::Backcolors color)
		{
			WinConsoleColors consoleColor = WinConsoleColors::White;

			switch (color)
			{
				case AnsiStyle::Backcolors::Dark_Black:
					consoleColor = WinConsoleColors::Black;
					break;
				case AnsiStyle::Backcolors::Dark_Red:
					consoleColor = WinConsoleColors::Red;
					break;
				case AnsiStyle::Backcolors::Dark_Green:
					consoleColor = WinConsoleColors::Green;
					break;
				case AnsiStyle::Backcolors::Dark_Yellow:
					consoleColor = WinConsoleColors::Yellow;
					break;
				case AnsiStyle::Backcolors::Dark_Blue:
					consoleColor = WinConsoleColors::Blue;
					break;
				case AnsiStyle::Backcolors::Dark_Magenta:
					consoleColor = WinConsoleColors::Purple;
					break;
				case AnsiStyle::Backcolors::Dark_Cyan:
					consoleColor = WinConsoleColors::Aqua;
					break;
				case AnsiStyle::Backcolors::Dark_White:
					consoleColor = WinConsoleColors::White;
					break;
				case AnsiStyle::Backcolors::Black:
					consoleColor = WinConsoleColors::Gray;
					break;
				case AnsiStyle::Backcolors::Red:
					consoleColor = WinConsoleColors::LightRed;
					break;
				case AnsiStyle::Backcolors::Green:
					consoleColor = WinConsoleColors::LightGreen;
					break;
				case AnsiStyle::Backcolors::Yellow:
					consoleColor = WinConsoleColors::LightYellow;
					break;
				case AnsiStyle::Backcolors::Blue:
					consoleColor = WinConsoleColors::LightBlue;
					break;
				case AnsiStyle::Backcolors::Magenta:
					consoleColor = WinConsoleColors::LightPurple;
					break;
				case AnsiStyle::Backcolors::Cyan:
					consoleColor = WinConsoleColors::LightAqua;
					break;
				case AnsiStyle::Backcolors::White:
					consoleColor = WinConsoleColors::BrightWhite;
					break;
				default: break;
			}

			SetConsoleTextAttribute(hConsole, 16 * (int)consoleColor);
		}

		void WinReset()
		{
			SetConsoleTextAttribute(hConsole, baseConsoleInfo.wAttributes);
		}

		void WinClear()
		{
			COORD cursorPos = { 0, 0 };
			CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
			GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
			DWORD written, cells = consoleInfo.dwSize.X * consoleInfo.dwSize.Y;
			FillConsoleOutputCharacterW(hConsole, ' ', cells, cursorPos, &written);
			FillConsoleOutputAttribute(hConsole, consoleInfo.wAttributes, cells, cursorPos, &written);
			SetConsoleCursorPosition(hConsole, cursorPos);
		}
	}

	inline void NewLine() noexcept
	{
		std::cout << '\n';
	}

	inline void SetForegroundColor(AnsiStyle::Forecolors color) noexcept
	{
	#if defined (Win32) || defined(Win64)
		SetWinForegroundColor(color);
	#else
		std::cout << color;
	#endif
	}

	inline void SetBackgroundColor(AnsiStyle::Backcolors color) noexcept
	{
	#if defined (Win32) || defined(Win64)
		SetWinBackgroundColor(color);
	#else
		std::cout << color;
	#endif
	}

	inline void Reset() noexcept
	{
	#if defined (Win32) || defined(Win64)
		WinReset();
	#else
		std::cout << AnsiStyle::Reset;
	#endif
	}

	inline void Clear() noexcept
	{
	#if defined (Win32) || defined(Win64)
		WinClear();
	#else
		std::cout << AnsiStyle::Clear << AnsiStyle::HomeCursor;
	#endif
	}

	template <class... Args>
	void Alert(Args... args) noexcept
	{
		SetForegroundColor(AnsiStyle::Forecolors::Yellow);
		(std::cout << ... << args) << '\n';
		Reset();
	}

	template <class... Args>
	void Error(Args... args) noexcept
	{
		SetForegroundColor(AnsiStyle::Forecolors::Red);
		(std::cerr << ... << args) << '\n';
		Reset();
	}

	template <class... Args>
	void Write(Args... args)
	{
		(std::cout << ... << args);
	}

	template <class... Args>
	void WriteColored(AnsiStyle::Forecolors color, Args... args) noexcept
	{
		SetForegroundColor(color);
		(std::cout << ... << args);
		Reset();
	}

	template <class... Args>
	void WriteLine(Args... args) noexcept
	{
		(std::cout << ... << args) << '\n';
	}

	template <class... Args>
	void WriteColoredLine(AnsiStyle::Forecolors color, Args... args) noexcept
	{
		SetForegroundColor(color);
		(std::cout << ... << args) << '\n';
		Reset();
	}
}