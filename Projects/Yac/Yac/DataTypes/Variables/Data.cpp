#include "Data.h"

using namespace Yac::Api;
using namespace Yac::DataTypes;

Data::Data() : _type(getVoidTypeSymbol()), _value(nullptr) {}
Data::Data(Object* value) : _type(getObjectTypeSymbol()), _value(value) {}
Data::Data(const TypeSymbol& type, Object* value) : _type(type), _value(value) {}