#pragma once

#include "Object.h"

namespace Yac::Api {

	struct Float final : Object {

	public:

		Float(float n = .0f) : _n(n) {}

		operator float() const { return _n; }

		virtual std::string ToString() const override { return std::to_string(_n); }

	private:

		float _n;
	};

}