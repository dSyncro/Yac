#include "SourceText.h"
#include "TextSpan.h"

using namespace Yac::Text;

SourceText::SourceText(std::string text)
{
	std::string line;

	unsigned int start = 0, length = 0;
	for (unsigned int i = 0; i < text.length(); i++)
	{
		if (text[i] != '\n') continue;

		length = i - start + 1;
		line = text.substr(start, length);
		_lines.push_back({ line, TextSpan(start, length) });
		start = i + 1;
	}

	unsigned int lastIndex = text.length() - 1;
	if (start == lastIndex) return;
	length = lastIndex - start + 1;
	line = text.substr(start, length);
	_lines.push_back({ line, TextSpan(start, length) });
}

SourceText::SourceText(std::ifstream& stream)
{
	unsigned int start = 0;
	std::string line;
	while (std::getline(stream, line))
	{
		unsigned int length = line.length();
		_lines.push_back({ line, TextSpan(start, length) });
		start += length;
	}
}

SourceText::~SourceText() {}