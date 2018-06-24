#include <iostream>
#include "Prototype.h"
//#include <Windows.h>



Prototype::Prototype()
{
	std::cout << "Pattern \"Prototype\"\n";
}


Prototype::~Prototype()
{
	std::cout << "Destructor ~Prototype() was called.\n";
}


void Prototype::run()
{

	std::cout << "Whole Pattern was terminated...\n";
}


PrototypeBase::PrototypeBase()
{
}


PrototypeBase::~PrototypeBase()
{
}


PrototypeChild01::PrototypeChild01()
{
}


PrototypeChild01::~PrototypeChild01()
{
}

PrototypeBase* PrototypeChild01::clone()
{
	return new PrototypeChild01;
}
