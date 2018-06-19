// ConsoleApplication4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "myclass.h"
#include <cassert>
#include <conio.h>



struct A
{
	virtual void method() = 0;
};

struct B : A
{
	void method() override { std::cout << "method\n"; }
};


int main()
{
	std::cout << "Hello\n";
	IMyClass mycl;
	std::cout << mycl.someAction() << "\n";
	assert(3 == 3 && "We need to do some..."); //Here is a Comment
	static_assert(sizeof(short) == 2, "Wau-wauwe have a problem.");

	A* b = new B;
	b->method();


	int key;
	while ((key = _getwch()) != 13)
	{
		std::cout << key << "\n";
	}



	return 0;
	

}

 