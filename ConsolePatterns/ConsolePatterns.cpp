// ConsolePatterns.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "factory_method.h"


using std::cout;

int main()
{
	std::cout << "Hello\n";

	cout << "============================================================================================\n";
	FactoryMethod fm;
	fm.run();

    return 0;
}

