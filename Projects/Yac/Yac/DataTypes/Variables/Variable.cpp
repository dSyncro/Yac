#include "Variable.h"

using namespace Yac::DataTypes;

Variable::Variable(const std::string& name, Data data) : _name(name), _data(data) {}

bool Yac::DataTypes::operator ==(const Variable& a, const Variable& b) noexcept { return a._name == b._name; }
