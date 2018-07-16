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

	subject.SetState({ 10,20,30 });
	subject.Attach(&observerB);
	subject.SetState({ 100,200,300 });

	std::cout << ">>> Whole Pattern was terminated...\n";
}
