#pragma once

#include <vector>

class SourceText
{
public:

	SourceText(const char* text);
	~SourceText();

	std::vector<const char*> GetLines() const noexcept { return _lines; }

private:

	std::vector<const char*> _lines;
};

