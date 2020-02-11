#include "AnsiStyle.h"
#include <sstream>

std::string AnsiStyle::CursorNavigation::Move(AnsiStyle::CursorNavigation::Direction direction, unsigned int step) noexcept
{
	std::ostringstream ss;
	ss << "\033[" << static_cast<int>(step) << (char)direction;
	return ss.str();
}

void AnsiStyle::Console::NewLine() noexcept
{
	std::cout << '\n';
}

void AnsiStyle::Console::SetForegroundColor(Forecolors color) noexcept
{
	std::cout << color;
}

void AnsiStyle::Console::SetBackgroundColor(Backcolors color) noexcept
{
	std::cout << color;
}

void AnsiStyle::Console::Reset() noexcept
{
	std::cout << AnsiStyle::Reset;
}