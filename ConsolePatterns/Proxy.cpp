#include "Proxy.h"


class Subject
{
public:
	virtual ~Subject() { }
	virtual void RequestComplexData() = 0;
	virtual void RequestSimpleData() = 0;
};


class RealSubject : public Subject
{
public:
	void RequestComplexData() override { std::cout << "Real object with big comlex data!" << std::endl; }
	void RequestSimpleData() override { std::cout << "Real object simple data." << std::endl; }
};

class ProxyClass : public Subject
{
public:
	~ProxyClass()
	{
		delete pointerToRealObject;
	}
	void RequestComplexData() override
	{
		std::cout << std::endl << "Proxy object trapping real method and redirect to real object!" << std::endl;
		if (pointerToRealObject == nullptr) pointerToRealObject = new RealSubject(); // delayed creation of real object
		pointerToRealObject->RequestComplexData();
	}
	void RequestSimpleData() override
	{
		std::cout << std::endl << "Proxy object trapping real method and check is real obect creted or not!" << std::endl;
		if (pointerToRealObject == nullptr) std::cout << "Proxy object is executing internal method" << std::endl;
		else pointerToRealObject->RequestSimpleData(); // if no real object created yet do proxy method
	}
private:
	Subject* pointerToRealObject = nullptr;
};



Proxy::Proxy()
{
	std::cout << "Pattern \"Proxy\"\n";
}


Proxy::~Proxy()
{
}


void Proxy::run()
{
	Subject& subject = ProxyClass();
	subject.RequestSimpleData();
	subject.RequestComplexData();
	subject.RequestSimpleData();
	std::cout << ">>> Whole Pattern was terminated...\n";
}
