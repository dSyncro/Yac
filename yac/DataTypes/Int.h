#pragma once

#include "Object.h"

namespace Yac {
	namespace DataTypes {

		struct Int : Object {

		public:

			Int(int n = 0) : _n(n) {}

			operator int() const { return _n; }

		private:

			int _n;
		};

	}
}