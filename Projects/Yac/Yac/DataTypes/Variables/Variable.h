#pragma once

#include "Data.h"

namespace Yac::DataTypes {

	struct Variable {

	public:

		Variable(const std::string& name, Data data);

		friend bool operator ==(const Variable& a, const Variable& b) noexcept;

		static bool referenceEqual(const Variable& a, const Variable& b) noexcept { return &a == &b; }

		void assign(Data data) noexcept { _data = data; }

		Data getData() const noexcept { return _data; }

	private:

		std::string _name;
		Data _data;
	};

	bool operator ==(const Variable& a, const Variable& b) noexcept;
}