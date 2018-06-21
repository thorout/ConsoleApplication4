#include <iostream>
#include "Prototype.h"



Prototype::Prototype()
{
	std::cout << "Constructor Prototype was called.\n";
}


Prototype::~Prototype()
{
	std::cout << "Destructor ~Prototype() was called.\n";
}


void Prototype::run()
{

	std::cout << "Whole Pattern was terminated...\n";
}
