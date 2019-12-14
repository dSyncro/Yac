#pragma once

#include "Object.h"

namespace Yac {
	namespace DataTypes {

		struct UInt : Object {

		public:

			UInt(unsigned int n = 0) : _n(n) {}

			operator unsigned int() const { return _n; }

		private:

			unsigned int _n;
		};

	}
}