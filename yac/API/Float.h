#pragma once

#include "Object.h"

namespace Yac {
	namespace Api {

		struct Float : Object {

		public:

			Float(float n = .0f) : _n(n) {}

			operator float() const { return _n; }

		private:

			float _n;
		};

	}
}