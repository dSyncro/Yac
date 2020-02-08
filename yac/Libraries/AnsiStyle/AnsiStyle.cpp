#include "AnsiStyle.h"
#include <sstream>

using namespace AnsiStyle;

std::string AnsiStyle::CursorNavigation::Move(AnsiStyle::CursorNavigation::Direction direction, unsigned int step) noexcept
{
	std::ostringstream ss;
	ss << "\033[" << static_cast<int>(step) << (char)direction;
	return ss.str();
}

namespace Console {

	void NewLine() noexcept
	{
		std::cout << '\n';
	}

	void Write(const std::string& text) noexcept
	{
		std::cout << text;
	}

	void WriteLine(const std::string& text, char lineSeparator) noexcept
	{
		std::cout << text << lineSeparator;
	}

	void SetForegroundColor(Forecolors color) noexcept
	{
		std::cout << color;
	}

	void SetBackgroundColor(Backcolors color) noexcept
	{
		std::cout << color;
	}

	void Reset() noexcept
	{
		std::cout << Reset;
	}
}