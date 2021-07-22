#include "SourceText.h"
#include "TextSpan.h"

using namespace Yac;

SourceText::SourceText(const std::string& text)
{
	std::string line;

	UIntT start = 0, length = 0;
	for (UIntT i = 0; i < text.length(); i++)
	{
		if (text[i] != '\n') continue;

		length = i - start;
		line = text.substr(start, length);
		_lines.emplace_back(line, TextSpan(start, length));
		start = i + 1;
	}

	UIntT len = static_cast<UIntT>(text.length());
	if (start == len) return;
	length = len - start;
	line = text.substr(start, length);
	_lines.emplace_back(line, TextSpan(start, length));
}

SourceText::SourceText(std::ifstream& stream)
{
	std::string line;

	UIntT start = 0;
	while (std::getline(stream, line))
	{
		UIntT length = static_cast<UIntT>(line.length());
		_lines.emplace_back(line, TextSpan(start, length));
		start += length;
	}
}

SourceText::~SourceText() {}