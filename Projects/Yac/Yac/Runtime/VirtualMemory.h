#pragma once

#include "ConversionTable.h"
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
			const Core::TypeSymbol& outType = typeToTypeSymbol<T>();
			void* valuePtr = retrieve(data);

			if (data.getType() == outType)
			{
				T* valuePointer = reinterpret_cast<T*>(valuePtr);
				return *valuePointer;
			}

			Cast cast = Cast(data.getType(), outType);
			VariableData converted = conversionTable.convert(cast, valuePtr);

			if (converted == VariableData::null()) 
				throw Errors::NotConvertibleToException(cast);

			return *reinterpret_cast<T*>(retrieve(converted));
		}

		template <typename T>
		const Core::TypeSymbol& typeToTypeSymbol()
		{
			if constexpr (std::is_same_v<T, bool>)
				return Core::TypeSymbol::getBoolTypeSymbol();

			else if constexpr (std::is_same_v<T, double>)
				return Core::TypeSymbol::getDoubleTypeSymbol();

			else if constexpr (std::is_same_v<T, float>)
				return Core::TypeSymbol::getFloatTypeSymbol();

			else if constexpr (std::is_same_v<T, IntT>)
				return Core::TypeSymbol::getIntTypeSymbol();

			//else if constexpr (std::is_same_v<T, double>)
			//	return Core::getObjectTypeSymbol();

			//else if constexpr (std::is_same_v<T, std::string>)
			//	return Core::getStringTypeSymbol();

			else if constexpr (std::is_same_v<T, UIntT>)
				return Core::TypeSymbol::getUIntTypeSymbol();

			else if constexpr (std::is_same_v<T, void>)
				return Core::TypeSymbol::getVoidTypeSymbol();

			//else if constexpr (std::is_same_v<T, void*>)
			//	return Core::getClassTypeSymbol();

			else return Core::TypeSymbol::getObjectTypeSymbol();
		}
		
	};

}