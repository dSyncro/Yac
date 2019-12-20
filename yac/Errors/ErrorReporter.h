#pragma once

#include "ErrorList.h"

namespace Yac {
	namespace Errors {

		class ErrorReporter {

		public:

			ErrorReporter() : _list(&ErrorManager) {}
			ErrorReporter(ErrorList* list) : _list(list) {}
			ErrorReporter(ErrorList& list) : _list(&list) {}

			ErrorList& GetList() const noexcept { return *_list; }

			void ReportUnexpectedToken(
				Yac::Syntax::TokenType expected,
				Yac::Syntax::TokenType found,
				const Yac::Text::TextSpan& span
			) const noexcept;

			void ReportUnknownToken(char c, const Yac::Text::TextSpan& span) const noexcept;

			void ReportNotABooleanLiteral(const std::string& text, const Yac::Text::TextSpan& span) const noexcept;
				
			void Clear() const noexcept { _list->Clear(); }

		private:

			ErrorList* _list;
		};

	}
}