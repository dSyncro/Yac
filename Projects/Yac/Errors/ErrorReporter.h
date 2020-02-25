#pragma once

#include "ErrorList.h"

namespace Yac::Errors {

	class ErrorReporter final {

	public:

		ErrorReporter(ErrorList* list) : _list(list) {}
		ErrorReporter(ErrorList& list) : _list(&list) {}

		inline ErrorList& GetList() const noexcept { return *_list; }

		void ReportUnexpectedToken(
			Yac::Syntax::TokenType expected,
			Yac::Syntax::TokenType found,
			const Yac::Text::TextSpan& span
		) const noexcept;

		void ReportUnknownToken(char c, const Yac::Text::TextSpan& span) const noexcept;

		void ReportNotABooleanLiteral(const std::string& text, const Yac::Text::TextSpan& span) const noexcept;

		inline void Clear() const noexcept { _list->Clear(); }

	private:

		ErrorList* _list;
	};
}