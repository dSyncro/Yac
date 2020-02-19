#pragma once

#include <string>
#include <vector>

#include "Error.h"

#include <yac/Syntax/Tokens/TokenType.h>

namespace Yac::Errors {

	struct ErrorList final {

	public:

		void Add(const Error& e) noexcept;
		bool Any() const noexcept;
		void Clear() noexcept;
		std::size_t Count() const noexcept;
		const Error& Get(unsigned int index) const;
		const Error& operator [](unsigned int index) const;

	private:

		std::vector<Error> _errors;
	};

	static ErrorList ErrorManager;
}