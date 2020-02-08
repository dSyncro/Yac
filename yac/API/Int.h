#pragma once

#include "Object.h"

namespace Yac {
	namespace Api {

		struct Int : Object {

		public:

			Int(int n = 0) : _n(n) {}

			operator int() const { return _n; }

		private:

			int _n;
		};

	}
}