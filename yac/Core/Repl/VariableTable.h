#pragma once

#include <string>
#include <unordered_map>

#include <yac/API/Object.h>

namespace Yac {
	namespace Core {

		template <typename T>
		struct ScopedPtr {

			ScopedPtr() {}
			ScopedPtr(T* ptr) : _ptr(ptr) { }
			~ScopedPtr() { delete _ptr; }

			T& operator *() const { return *_ptr; }
			T* operator ->() const { return _ptr; }
			T* Get() const { return _ptr; }

		private:

			T* _ptr = nullptr;
		};

		class VariableTable {

		public:

			const Yac::Api::Object nullObj = Yac::Api::Object();

			template <typename T, typename = typename std::enable_if<std::is_base_of<Yac::Api::Object, T>::value>::type>
			inline T& Get(const std::string& key) const noexcept
			{
				auto it = _map.find(key);
				if (it == _map.end()) return (T&)nullObj;
				return (T&)*(it->second);
			}

			template <typename T, typename = typename std::enable_if<std::is_base_of<Yac::Api::Object, T>::value>::type>
			inline void Set(const std::string& key, const T& value) noexcept 
			{ 
				std::unordered_map<std::string, Yac::Api::Object*>::iterator it = _map.find(key);

				// Allocate variable
				std::size_t size = sizeof(T);
				Yac::Api::Object* reference = (Yac::Api::Object*)std::malloc(size);
				std::memcpy(reference, &value, size);

				// If variable exists
				if (it != _map.end())
				{
					delete it->second; // Delete old one
					it->second = reference; // Update reference
					return;
				}

				_map[key] = reference; // Elsewise create new entry
			}

		private:

			std::unordered_map<std::string, Yac::Api::Object*> _map;
		};

	}
}