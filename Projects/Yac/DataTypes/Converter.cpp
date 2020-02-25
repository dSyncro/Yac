#include "Converter.h"

using namespace Yac::Api;
using namespace Yac::DataTypes;

Converter::Converter(const TypeSymbol& from, const TypeSymbol& to, Data(*callback)(const Object*))
	: _from(from), _to(to), _callback(callback) { }

Data Converter::Convert(const Data& data) const
{
	if (data.type() == _from) return _callback(data.value());
	throw std::exception();
}
