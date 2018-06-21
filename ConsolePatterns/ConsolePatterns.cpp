// ConsolePatterns.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <memory>
#include "factory_method.h"
#include "Prototype.h"


using std::cout;

int main()
{
	std::cout << "Hello\n";

	cout << "============================================================================================\n";
	FactoryMethod fm;
	fm.run(2);
	cout << "============================================================================================\n";

	cout << "============================================================================================\n";
	Prototype pr;
	pr.run();
	cout << "============================================================================================\n";

    return 0;
}

