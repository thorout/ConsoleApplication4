#include "Mediator.h"



Mediator::Mediator()
{
	std::cout << "Pattern \"Command\"\n";
}


Mediator::~Mediator()
{
}


void Mediator::run()
{
	std::cout << ">>> Whole Pattern was terminated...\n";
}
