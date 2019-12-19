#pragma once

#include <string>
#include <vector>

struct Line {

public:

	Line(std::string string, unsigned int start, unsigned int end) 
		: _string(string), _start(start), _end(end) {}

	inline const std::string& text() const noexcept { return _string; }
	inline unsigned int start() const noexcept { return _start; }
	inline unsigned int end() const noexcept { return _end; }

private:

	std::string _string;
	unsigned int _start, _end;
};

namespace Yac {
	namespace Text {

		class SourceText
		{
		public:

			SourceText(const char* text);
			~SourceText();

			std::vector<Line> GetLines() const noexcept { return _lines; }

		private:

			std::vector<Line> _lines;
		};


	}
}