#pragma once

#include "Conversion/ConversionTable.h"
#include "Operator/OperatorOverloadTable.h"

#include <Yac/Core/Errors/Exceptions/NotConvertibleToException.h>

namespace Yac::Runtime {

	class VirtualMemory {

	public:

		Stack stack;
		ConversionTable conversionTable;
		OperatorOverloadTable operatorTable;

		VirtualMemory();

		void* retrieve(VariableData data);

		ByteT* allocate(const Core::TypeSymbol& type) const noexcept;

		template <typename T>
		T getValue(VariableData data)
		{
			const Core::TypeSymbol& outType = Core::toTypeSymbol<T>();
			void* valuePtr = retrieve(data);

			if (data.getType() == outType)
				return *reinterpret_cast<T*>(valuePtr);

			Cast cast = Cast(data.getType(), outType);
			VariableData converted = conversionTable.convert(cast, valuePtr);

			if (converted == VariableData::null()) 
				throw Errors::NotConvertibleToException(cast);

			return *reinterpret_cast<T*>(retrieve(converted));
		}
		
	};

}