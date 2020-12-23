#pragma once

#include <functional>
#include <string>
#include <unordered_map>

#include "Cast.h"
#include "Stack.h"
#include "VariableData.h"

namespace Yac::Runtime {

	using Converter = VariableData(*)(Stack& stack, const void* value);

	class ConversionTable final {

	public:

		void bind(Cast cast, Converter converter) noexcept;
		void bind(const Core::TypeSymbol& fromType, const Core::TypeSymbol& toType, Converter converter) noexcept;

		bool contains(Cast cast) const noexcept;

		VariableData convert(Cast cast, const void* value) const;

	private:

		ConversionTable(Stack& stack);

		std::unordered_map<Cast, Converter> _table;
		Stack* _stack;

		friend class VirtualMemory;

	};
}
