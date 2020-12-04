#pragma once

#include <string>
#include <vector>

#include "Error.h"

#include <Yac/Core/Primitives.h>
#include <Yac/Syntax/Tokens/TokenType.h>

namespace Yac::Errors {

	struct ErrorList final {

	public:

		void add(const Error& e) noexcept;
		bool any() const noexcept;
		void clear() noexcept;

		void reportUnexpectedToken(
			Syntax::TokenType expected,
			Syntax::TokenType found,
			const Text::TextSpan& span
		) noexcept;

		void reportUnknownToken(char c, const Text::TextSpan& span) noexcept;

		void reportNotABooleanLiteral(const std::string& text, const Text::TextSpan& span) noexcept;

		std::size_t count() const noexcept;
		const Error& get(UIntT index) const;
		const Error& operator [](UIntT index) const;

	private:

		std::vector<Error> _errors;
	};

	inline ErrorList& getDefaultErrorList()
	{
		static ErrorList list;
		return list;
	}
}