#include "Data.h"

#include <DataTypes/Types/StaticTypeSymbols.h>

using namespace Yac::Api;
using namespace Yac::DataTypes;

Data::Data() : _type(VoidTypeSymbol), _value(nullptr) {}
Data::Data(Yac::Api::Object* value) : _type(ObjectTypeSymbol), _value(value) {}
Data::Data(const TypeSymbol& type, Yac::Api::Object* value) : _type(type), _value(value) {}