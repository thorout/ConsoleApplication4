#pragma once
#include <iostream>


class Implementator
{
public:
	virtual ~Implementator() {	}
	virtual void someMethodImpl() = 0;
};


class RealImplement : public Implementator
{
public:
	void someMethodImpl() override 
	{
		std::cout << "RealImplementation Method \n";
	}
};


class Abstraction
{
public:
	Abstraction() : link_to_implement(new RealImplement()) {}
	~Abstraction() { delete link_to_implement; }
	void someMethod() 
	{
		link_to_implement->someMethodImpl();
	}
private:
	Implementator* link_to_implement;
};




class Bridge
{
public:
	Bridge();
	~Bridge();
	void run();
};

