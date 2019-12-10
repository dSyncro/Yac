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
			);

			void ReportUnknownToken(char c, const Yac::Text::TextSpan& span);

			void Clear() { _list->Clear(); }

		private:

			ErrorList* _list;
		};

	}
}