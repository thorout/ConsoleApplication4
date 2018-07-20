#include "Visitor.h"



Visitor::Visitor()
{
	std::cout << "Pattern \"Visitor\"\n";
}


Visitor::~Visitor()
{
}


void Visitor::run()
{
	std::cout << ">>> Whole Pattern was terminated...\n";
}
