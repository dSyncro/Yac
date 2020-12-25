#pragma once

#include "Object.h"

#include <Yac/Core/Primitives.h>

namespace Yac::Api {

	struct UInt final : Object {

	public:

		UInt(UIntT n = 0) : _n(n) {}

		operator UIntT() const { return _n; }

		virtual std::string toString() const override { return std::to_string(_n); }

	private:

		UIntT _n;
	};

}