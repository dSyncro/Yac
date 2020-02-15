#pragma once

#include "../AnsiStyle/AnsiStyle.h"

namespace Console {

	inline extern void NewLine() noexcept;
	inline extern void SetForegroundColor(AnsiStyle::Forecolors color) noexcept;
	inline extern void SetBackgroundColor(AnsiStyle::Backcolors color) noexcept;
	inline extern void Reset() noexcept;
	inline extern void Clear() noexcept;

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
		std::cout << color;
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
		std::cout << color;
		(std::cout << ... << args) << '\n';
		Reset();
	}
}