#pragma once

#include <cstring>
#include <string>
#include <unordered_map>

#include <API/Object.h>

namespace Yac::Core {
	
	class VariableTable final {

	public:

		template <typename T>
		Yac::Api::EnableIfObject<T> get(const std::string& key) const noexcept
		{
			std::unordered_map<std::string, Yac::Api::Object*>::const_iterator it = _map.find(key);
			if (it == _map.end()) return T();
			return (T&)*(it->second);
		}

		template <typename T>
		void set(const std::string& key, const Yac::Api::EnableIfObject<T>& value) noexcept
		{
			std::unordered_map<std::string, Yac::Api::Object*>::iterator it = _map.find(key);

			// Allocate variable
			Yac::Api::Object* reference = new Yac::Api::Object();

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
