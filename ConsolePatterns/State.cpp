#include "State.h"



State::State()
{
	std::cout << "Pattern \"State\"\n";
}


State::~State()
{
}


void State::run()
{
	std::cout << ">>> Whole Pattern was terminated...\n";
}
