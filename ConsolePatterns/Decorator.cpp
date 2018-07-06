#include "Decorator.h"



Decorator::Decorator()
{
	std::cout << "Pattern \"Decoder\"\n";
}


Decorator::~Decorator()
{
}


void Decorator::run()
{
	std::cout << ">>> Whole Pattern was terminated...\n";
}
