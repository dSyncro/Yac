#pragma once

#include "Object.h"

namespace Yac::Api {

	struct Int final : Object {

	public:

		Int(int n = 0) : _n(n) {}

		operator IntT() const { return _n; }

		virtual std::string toString() const override { return std::to_string(_n); }

	private:

		IntT _n;
	};
}