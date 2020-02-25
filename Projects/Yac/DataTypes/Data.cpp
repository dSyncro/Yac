#include "Data.h"

using namespace Yac::Api;
using namespace Yac::DataTypes;

Data::Data(const TypeSymbol& type, Yac::Api::Object* value) : _type(&type), _value(value) {}

Data::~Data() { Dispose(); }