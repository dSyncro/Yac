#pragma once

#include <string>
#include <vector>

#include "Error.h"

#include <Core/Primitives.h>
#include <Syntax/Tokens/TokenType.h>

namespace Yac::Errors {

	struct ErrorList final {

	public:

		void add(const Error& e) noexcept;
		bool any() const noexcept;
		void clear() noexcept;

		void reportUnexpectedToken(
			Yac::Syntax::TokenType expected,
			Yac::Syntax::TokenType found,
			const Yac::Text::TextSpan& span
		) noexcept;

		void reportUnknownToken(char c, const Yac::Text::TextSpan& span) noexcept;

		void reportNotABooleanLiteral(const std::string& text, const Yac::Text::TextSpan& span) noexcept;

		std::size_t count() const noexcept;
		const Error& get(Yac::UInt index) const;
		const Error& operator [](Yac::UInt index) const;

	private:

		std::vector<Error> _errors;
	};

	inline ErrorList& getDefaultErrorList()
	{
		static ErrorList list;
		return list;
	}
}