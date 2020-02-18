#pragma once

#include "Object.h"

namespace Yac {
	namespace Api {

		struct Double : Object {

		public:

			Double(double n = 0) : _n(n) {}

			operator double() const { return _n; }

			virtual std::string ToString() const override { return std::to_string(_n); }

		private:

			double _n;
		};

	}
}