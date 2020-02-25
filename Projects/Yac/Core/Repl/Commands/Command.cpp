#include "Command.h"

using namespace Yac::Core;

Command::Command(std::string command, const std::vector<std::string> parameters) : _cmd(command), _params(parameters) {}

Command Command::Parse(std::string line) noexcept
{
	line.erase(0, 1); // remove '#'

	std::string cmd;
	std::vector<std::string> params;

	bool isCmd = true;
	unsigned int start = 0;

	// Parse parameters
	for (unsigned int i = 0; i < line.length(); i++)
	{
		if (line[i] != ' ') continue;

		unsigned int length = i - start;
		std::string token = line.substr(start, length);

		if (isCmd)
		{
			cmd = token;
			isCmd = false;
		}
		else params.push_back(token);

		start = i + 1;
	}

	// Last or Unique parameter
	if (start < line.length())
	{
		std::size_t length = line.length() - start;
		std::string token = line.substr(start, length);

		if (isCmd)
		{
			cmd = token;
			isCmd = false;
		}
		else params.push_back(token);
	}

	return Command(cmd, params);
}
