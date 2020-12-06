#pragma once

#define ELEMENT_TO_STRING(element) case element: return #element;
#define ENUM_ELEMENT_TO_STRING(enumeration, element) case enumeration::element: return #element;