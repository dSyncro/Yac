#pragma once

#include "Object.h"

namespace Yac {
	namespace Api {

		struct Double : Object {

		public:

			Double(double n = 0) : _n(n) {}

			operator double() const { return _n; }

		private:

			double _n;
		};

	}
}