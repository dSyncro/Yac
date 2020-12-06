#pragma once

#include <fstream>
#include <string>
#include <vector>

#include "Line.h"

namespace Yac::Core {

	class SourceText final
	{
	public:

		SourceText(const std::string& text);
		SourceText(std::ifstream& stream);
		~SourceText();

		UIntT getLineCount() const noexcept { return static_cast<UIntT>(_lines.size()); }
		const Line& operator [](UIntT index) const { return _lines[index]; }
		const std::vector<Line>& getLines() const noexcept { return _lines; }

	private:

		std::vector<Line> _lines;
	};
}