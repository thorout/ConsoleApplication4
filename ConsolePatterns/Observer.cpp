#include "Observer.h"



Observer::Observer()
{
	std::cout << "Pattern \"Observer\"\n";
}


Observer::~Observer()
{
}


void Observer::run()
{
	ConcreteObserverA observerA;
	ConcreteObserverB observerB;
	ConcreteObserverC observerC;
	ConcreteSubject subject;

	subject.Attach(&observerA);
	subject.Attach(&observerB);
	subject.Attach(&observerC);
	subject.Notify();

	subject.Dettach(&observerB);
	subject.Notify();

	std::cout << ">>> Whole Pattern was terminated...\n";
}
