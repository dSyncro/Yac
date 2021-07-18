#pragma once

#include "Object.h"

namespace Yac::Api {

	struct Float final : public Object {

	public:

		Float(float n = .0f) : _n(n) {}

		operator float() const { return _n; }

	private:

		float _n;
	};

}