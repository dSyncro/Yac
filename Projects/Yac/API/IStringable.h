#pragma once

#include <string>

struct IStringable {

	virtual std::string ToString() const = 0;

};