#include "Command.h"



Command::Command()
{
	std::cout << "Pattern \"Command\"\n";
}


Command::~Command()
{
}


void Command::run()
{
	std::cout << ">>> Whole Pattern was terminated...\n";
}
