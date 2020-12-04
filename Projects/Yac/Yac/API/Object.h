#pragma once

#include <string>

#include "IStringable.h"

#include <Yac/Errors/Exceptions/ObjectConversionException.h>

namespace Yac::Api {

	struct Object : IStringable {

	public:

		virtual ~Object() {}

		template <typename T>
		static T cast(const Object* object)
		{
			const Object* reference = object;
			const T* cast = dynamic_cast<const T*>(object);
			if (cast) return *cast;
			throw Yac::Errors::ObjectConversionException();
		}

		template <typename T, typename = typename std::enable_if<std::is_base_of<Object, T>::value>::type>
		operator T() const { return Object::cast<T>(this); }

		virtual std::string toString() const { return "Object[" + std::to_string((std::size_t)this) + "]"; };
	};

	template <typename T>
	using EnableIfObject = std::enable_if_t<std::is_base_of_v<Yac::Api::Object, T>, T>;

}