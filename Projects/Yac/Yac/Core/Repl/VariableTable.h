#pragma once

#include <cstring>
#include <string>
#include <unordered_map>

#include <Yac/API/Object.h>

namespace Yac::Core {
	
	class VariableTable final {

	public:

		template <typename T>
		Api::EnableIfObject<T> get(const std::string& key) noexcept
		{
			auto it = _map.find(key);
			if (it == _map.end()) return T();
			return *(T*)it->second;
		}

		template <typename T>
		void set(const std::string& key, const Api::EnableIfObject<T>& value) noexcept
		{
			auto it = _map.find(key);

			// Allocate variable
			Api::Object* reference = new Api::Object();

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

		std::unordered_map<std::string, Api::Object*> _map;
	};

}
