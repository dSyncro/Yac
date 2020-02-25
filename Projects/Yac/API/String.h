#pragma once

#include "Object.h"

namespace Yac::Api {

	struct String final : Object {

	public:

		String(std::string s = "") : _string(s) {}

		operator std::string() const { return _string; }

		virtual std::string ToString() const override { return _string; }

	private:

		std::string _string;
	};

}