#pragma once

#include <cstring>
#include <string>
#include <unordered_map>

namespace Yac::Core {
	
	class VariableTable final {

	public:

		template <typename T>
		T get(const std::string& key) noexcept
		{
			auto it = _map.find(key);
			if (it == _map.end()) return T();
			return *reinterpret_cast<T*>(it->second);
		}

		template <typename T>
		void set(const std::string& key, const T& value) noexcept
		{
			auto it = _map.find(key);

			// Allocate variable
			T* reference = new T();

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

		std::unordered_map<std::string, void*> _map;
	};

}
