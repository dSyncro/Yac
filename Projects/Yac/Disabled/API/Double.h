#pragma once

#include "Object.h"

namespace Yac::Api {

	struct Double final : public Object {

	public:

		Double(double n = 0) : _n(n) {}

		operator double() const { return _n; }

	private:

		double _n;
	};

}