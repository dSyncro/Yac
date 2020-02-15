#pragma once

#include "Data.h"

namespace Yac {
	namespace DataTypes {

		struct Variable {

		public:

			Variable(std::string name, Data data);

			friend bool operator ==(const Variable& a, const Variable& b) noexcept;

			inline static bool ReferenceEqual(const Variable& a, const Variable& b) noexcept { return &a == &b; }

			inline void Assign(Data data) noexcept { _data = data; }

			inline Data Value() const noexcept { return _data; }

		private:

			std::string _name;
			Data _data;
		};

	}
}