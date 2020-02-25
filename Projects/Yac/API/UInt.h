#pragma once

#include "Object.h"

namespace Yac::Api {

	struct UInt final : Object {

	public:

		UInt(unsigned int n = 0) : _n(n) {}

		operator unsigned int() const { return _n; }

		virtual std::string ToString() const override { return std::to_string(_n); }

	private:

		unsigned int _n;
	};

}