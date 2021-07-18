#pragma once

#include "Object.h"

namespace Yac::Api {

	struct Bool final : public Object {

	public:

		Bool(bool b = false) : _b(b) {}

		operator bool() const { return _b; }

	private:

		bool _b;
	};

}