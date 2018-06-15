// ConsoleApplication4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "myclass.h"
#include <cassert>

int main()
{
	std::cout << "Hello\n";
	IMyClass mc;
	std::cout << mc.someAction() << "\n";
	assert(3 == 3 && "We need to do some..."); //Here is a Comment
	static_assert(sizeof(short) == 2, "Wau-wauwe have a problem.");
    return 0;
}

