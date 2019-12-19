#pragma once

#include <fstream>
#include <string>
#include <vector>

#include "Line.h"

namespace Yac {
	namespace Text {

		class SourceText
		{
		public:

			SourceText(std::string text);
			SourceText(std::ifstream& stream);
			~SourceText();

			unsigned int lineCount() const noexcept { return _lines.size(); }
			const Line& operator [](unsigned int index) const { return _lines[index]; }
			const std::vector<Line>& GetLines() const noexcept { return _lines; }

		private:

			std::vector<Line> _lines;
		};


	}
}