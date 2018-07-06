// ConsoleApplication4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "myclass.h"
#include <cassert>
#include <conio.h>
#include <ratio>



struct A
{
	virtual void method() = 0;
};

struct B : A
{
	void method() override { std::cout << "method\n"; }

};


void foo(A& b)
{
	b.method();
}

int main()
{
	std::cout << "Hello\n";
	IMyClass mycl;
	std::cout << mycl.someAction() << "\n";
	assert(3 == 3 && "We need to do some..."); //Here is a Comment
	static_assert(sizeof(short) == 2, "Wau-wau! We have a problem.");

	//A* b = new B;
	//b->method();


	int key;
	while ((key = _getwch()) != 13)
	{
		std::cout << key << "\n";
	}

	B bb;
	A& aa = bb;
	foo(aa);
	foo(bb);

	std::cout << std::milli::num << "/" << std::milli::den << " " << std::milli << std::endl;


	return 0;
}

