#pragma once

#include <type_traits>

namespace Yac::Api {

	struct Object { };

	template <typename T>
	using EnableIfObject = std::enable_if_t<std::is_base_of_v<Object, T>, T>;

}