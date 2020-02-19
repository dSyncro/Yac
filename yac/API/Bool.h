#pragma once

#include "Object.h"

namespace Yac::Api {

	struct Bool final : Object {

	public:

		Bool(bool b = false) : _b(b) {}

		operator bool() const { return _b; }

		virtual std::string ToString() const override { return _b == 0 ? "false" : "true"; }

	private:

		bool _b;
	};

}