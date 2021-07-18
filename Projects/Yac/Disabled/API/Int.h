#pragma once

#include "Object.h"

#include <Yac/Core/Primitives.h>

namespace Yac::Api {

	struct Int final : public Object {

	public:

		Int(int n = 0) : _n(n) {}

		operator IntT() const { return _n; }

	private:

		IntT _n;
	};
}