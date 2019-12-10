#pragma once

#include <string>
#include <vector>

#include "Error.h"

#include <yac/Syntax/Tokens/TokenType.h>

namespace Yac {
	namespace Errors {

		struct ErrorList {

		public:

			void Add(const Error& e) noexcept { _errors.push_back(e); }

			bool Any() const noexcept { return _errors.size() > 0; }

			void Clear() noexcept { _errors.clear(); }

			unsigned int Count() const noexcept { return _errors.size(); }

			const Error& Get(unsigned int index) const;

			const Error& operator [](unsigned int index) const { return Get(index); }

		private:

			std::vector<Error> _errors;
		};

		static ErrorList ErrorManager;

	}
}