#pragma once

#include <Yac/Core/Types/TypeSymbol.h>

namespace Yac::Runtime {

	struct VariableData {

	public:

		VariableData(const Core::TypeSymbol& type, void* data)
			: _type(&type), _data(data), _isOnStack(false) { }

		VariableData(const Core::TypeSymbol& type = Core::TypeSymbol::getVoidTypeSymbol(), ptrdiff_t offset = 0)
			: _type(&type), _offset(offset), _isOnStack(true) { }

		static const VariableData& null() noexcept
		{
			static VariableData null;
			return null;
		}

		const Core::TypeSymbol& getType() const noexcept { return *_type; }

		void* getData() const noexcept { return _data; }
		ptrdiff_t getOffset() const noexcept { return _offset; }

		bool isOnStack() const noexcept { return _isOnStack; }

		bool shouldBeValid() const noexcept { return *_type != Core::TypeSymbol::getVoidTypeSymbol(); }

		bool operator ==(const VariableData& other) const noexcept { return _type == other._type && _data == other._data; }
		bool operator !=(const VariableData& other) const noexcept { return !(*this == other); }

	private:

		const Core::TypeSymbol* _type;

		union {
			void* _data;
			ptrdiff_t _offset;
		};

		bool _isOnStack;

	};

}