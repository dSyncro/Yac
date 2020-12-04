#pragma once

#include <string>

struct IStringable {

	virtual std::string toString() const = 0;

};