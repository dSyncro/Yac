#pragma once

#include <variant>

#include <Yac/Core/Primitives.h>

namespace Yac {

	using Numeric = std::variant<IntT, UIntT, float, double>;

}