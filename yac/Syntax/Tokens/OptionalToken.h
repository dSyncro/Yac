#pragma once

#include "Token.h"

namespace Yac {
	namespace Syntax {

		struct OptionalToken {

		public:

			OptionalToken() : _token(Token()), _present(false) {}
			OptionalToken(const Token& token, bool isPresent) : _token(token), _present(isPresent) {}

			inline const Token& token() const noexcept { return _token; }
			inline bool IsPresent() const noexcept { return _present; }

		private:

			const Token& _token;
			bool _present;
		};

	}
}