#include "SourceText.h"

using namespace Yac::Text;

SourceText::SourceText(const char* text)
{
	std::string txt = text;
	std::string line;

	unsigned int start = 0, length = 0;
	for (unsigned int i = 0; i < txt.length(); i++)
	{
		if (text[i] != '\n') continue;

		length = i - start;
		line = txt.substr(start, length);
		_lines.push_back({ line, start, i });
		start = i + 1;
	}

	unsigned int lastIndex = txt.length() - 1;
	if (start == lastIndex) return;
	length = lastIndex - start;
	line = txt.substr(start, length);
	_lines.push_back({ line, start, lastIndex });
}

SourceText::~SourceText() {}