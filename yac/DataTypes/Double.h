#pragma once

#include "Object.h"

namespace Yac {
	namespace DataTypes {

		struct Double : Object {

		public:

			Double(double n = 0) : _n(n) {}

			operator double() const { return _n; }

		private:

			double _n;
		};

	}
}