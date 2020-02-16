#include "SourceText.h"
#include "TextSpan.h"

using namespace Yac::Text;

SourceText::SourceText(std::string text)
{
	std::string line;

	std::size_t start = 0, length = 0;
	for (std::size_t i = 0; i < text.length(); i++)
	{
		if (text[i] != '\n') continue;

		length = i - start;
		line = text.substr(start, length);
		_lines.push_back({ line, TextSpan(start, length) });
		start = i + 1;
	}

	std::size_t len = text.length();
	if (start == len) return;
	length = len - start;
	line = text.substr(start, length);
	_lines.push_back({ line, TextSpan(start, length) });
}

SourceText::SourceText(std::ifstream& stream)
{
	std::size_t start = 0;
	std::string line;
	while (std::getline(stream, line))
	{
		std::size_t length = line.length();
		_lines.push_back({ line, TextSpan(start, length) });
		start += length;
	}
}

SourceText::~SourceText() {}