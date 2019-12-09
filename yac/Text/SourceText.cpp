#include "SourceText.h"

SourceText::SourceText(const char* text)
{
	const char* txt = text;
	_lines.push_back(txt);
	while (*txt++)
		if (*txt == '\n') _lines.push_back(txt + 1);
}

SourceText::~SourceText() {}