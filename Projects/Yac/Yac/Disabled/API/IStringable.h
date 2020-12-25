#pragma once

#include <string>

struct IStringable {

	virtual ~IStringable() = default;

	virtual std::string toString() const = 0;

};