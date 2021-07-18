#pragma once

#include <memory>

#define ELEMENT_TO_STRING(element) case element: return #element;
#define ENUM_ELEMENT_TO_STRING(enumeration, element) case enumeration::element: return #element;

template<typename T>
using Unique = std::unique_ptr<T>;

template<typename T, typename ... Args>
constexpr Unique<T> createUnique(Args&& ... args)
{
	return std::make_unique<T>(std::forward<Args>(args)...);
}

template <typename ReturnType, typename... Args>
using FunctionHandler = ReturnType(*)(Args...);