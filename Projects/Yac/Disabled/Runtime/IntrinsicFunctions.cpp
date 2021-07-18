#include "IntrinsicFunctions.h"

#include <Console.h>

using namespace Yac;
using namespace Yac::Runtime;

void Runtime::print(IntT text)
{
	Console::write(text);
}

IntT Runtime::input()
{
	IntT text;
	std::cin >> text;
	return text;
}
