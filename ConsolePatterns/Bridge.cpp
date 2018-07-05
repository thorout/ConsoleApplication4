#include "Bridge.h"



Bridge::Bridge()
{
	std::cout << "Pattern \"Bridge\"\n";
}


Bridge::~Bridge()
{
}


void Bridge::run()
{

	Abstraction abstraction;
	abstraction.someMethod();
	std::cout << ">>> Whole Pattern was terminated...\n";
}
