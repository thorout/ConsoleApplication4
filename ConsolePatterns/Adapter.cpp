#include "Adapter.h"
#include <iostream>


Adapter::Adapter()
{
	std::cout << "Pattern \"Adapter\"\n";
}

Adapter::~Adapter()
{

}


void Adapter::run()
{
	AdapterClass adapter;

	adapter.nativeMethod01();
	adapter.nativeMethod02();

	std::cout << ">>> Whole Pattern was terminated...\n";
}
