#pragma once

#include <string>
#include <vector>

#include "Error.h"

#include <yac/Syntax/Tokens/TokenType.h>

namespace Yac {
	namespace Errors {

		struct ErrorList {

		public:

			void Add(const Error& e) noexcept;
			bool Any() const noexcept;
			void Clear() noexcept;
			unsigned int Count() const noexcept;
			const Error& Get(unsigned int index) const;
			const Error& operator [](unsigned int index) const;

		private:

			std::vector<Error> _errors;
		};

		static ErrorList ErrorManager;

	}
}