#include <iostream>
#include <memory>
#include "Prototype.h"




Prototype::Prototype()
{
	std::cout << "Pattern \"Prototype\"\n";
}


Prototype::~Prototype()
{
}


void Prototype::run()
{
	auto p01 = std::shared_ptr<PrototypeChild01>(new PrototypeChild01);
	auto p02 = std::shared_ptr<PrototypeChild02>(new PrototypeChild02);

	p01->some_parameter01 = 1000;
	p02->some_parameter02 = 2000;
	p02->some_parameter22 = 2200;

	std::cout << "Parameters: " << p01->some_parameter01 << " " << p02->some_parameter02 << " " << p02->some_parameter22 << " " << "\n";

	auto p11 = std::shared_ptr<PrototypeChild01>(static_cast<PrototypeChild01*>(p01->clone()));
	auto p12 = std::shared_ptr<PrototypeChild02>(static_cast<PrototypeChild02*>(p02->clone()));
	
	std::cout << "Clone data: " << p11->some_parameter01 << " " << p12->some_parameter02 << " " << p12->some_parameter22 << " " << "\n";

	std::cout << ">>> Whole Pattern was terminated...\n";
}


PrototypeBase::PrototypeBase()
{
}


PrototypeBase::~PrototypeBase()
{
	std::cout << "~PrototypeBase()\n";
}


PrototypeChild01::PrototypeChild01()
{
}


PrototypeChild01::~PrototypeChild01()
{

		std::cout << "~PrototypeChild01\n";
}

PrototypeBase* PrototypeChild01::clone()
{
	PrototypeChild01* p = new PrototypeChild01;
	p->some_parameter01 = this->some_parameter01;
	return p;
}

PrototypeChild02::PrototypeChild02()
{
}


PrototypeChild02::~PrototypeChild02()
{
	std::cout << "~PrototypeChild02()\n";
}

PrototypeBase* PrototypeChild02::clone()
{
	PrototypeChild02* p = new PrototypeChild02;
	p->some_parameter02 = this->some_parameter02;
	p->some_parameter22 = this->some_parameter22;
	return p;
}