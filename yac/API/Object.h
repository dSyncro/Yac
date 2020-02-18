#pragma once

#include <string>

#include <yac/Errors/Exceptions/ObjectConversionException.h>

namespace Yac {
	namespace Api {

		struct Object {

		public:

			virtual ~Object() {}

			template <typename T>
			static T Cast(const Object* object)
			{
				const Object* reference = object;
				const T* cast = dynamic_cast<const T*>(object);
				if (cast) return *cast;
				else throw Yac::Errors::ObjectConversionException();
			}

			template <typename T, typename = typename std::enable_if<std::is_base_of<Object, T>::value>::type>
			operator T() const { return Object::Cast<T>(this); }

			virtual std::string ToString() const { return "Object[" + std::to_string((std::size_t)this) + "]"; };
		};

	}
}