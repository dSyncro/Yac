#pragma once

#include "Object.h"

namespace Yac::Api {

	struct Double final : Object {

	public:

		Double(double n = 0) : _n(n) {}

		operator double() const { return _n; }

		virtual std::string ToString() const override { return std::to_string(_n); }

	private:

		double _n;
	};

}