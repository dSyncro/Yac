#include "Console.h"

using namespace AnsiStyle;

void Console::NewLine() noexcept
{
	std::cout << '\n';
}

void Console::SetForegroundColor(Forecolors color) noexcept
{
	std::cout << color;
}

void Console::SetBackgroundColor(Backcolors color) noexcept
{
	std::cout << color;
}

void Console::Reset() noexcept
{
	std::cout << AnsiStyle::Reset;
}

void Console::Clear() noexcept
{
	std::cout << AnsiStyle::Clear;
}