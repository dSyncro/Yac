#include <iostream>

#include "Core/Repl/Repl.h"

using namespace Yac::Core;

int main(int argc, char** argv)
{
	Repl repl = Repl();
	repl.Run();
}