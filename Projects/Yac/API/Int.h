#pragma once

#include "Object.h"

namespace Yac::Api {

	struct Int final : Object {

	public:

		Int(int n = 0) : _n(n) {}

		operator int() const { return _n; }

		virtual std::string ToString() const override { return std::to_string(_n); }

	private:

		int _n;
	};
}