#pragma once

namespace Yac::Syntax {

	enum class Keyword {
		False,
		True,
		Let,
		If,
		Else,
		For,
		While,
		Unknown
	};

	inline Keyword toKeyword(const std::string& text)
	{
		if (text == "true") return Keyword::True;
		else if (text == "false") return Keyword::False;
		else if (text == "let") return Keyword::Let;
		else if (text == "if") return Keyword::If;
		else if (text == "else") return Keyword::Else;
		else if (text == "for") return Keyword::For;
		else if (text == "while") return Keyword::While;
		else return Keyword::Unknown;
	}
}