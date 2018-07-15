#include "Memento.h"



Memento::Memento()
{	
	std::cout << "Pattern \"Memento\"\n";
}


Memento::~Memento()
{
}


void Memento::run()
{
	Originator origin;
	origin.PrintState();
	MementoClass* memento = origin.CreateMemento();
	origin.ChangeState();
	origin.PrintState();
	origin.SetMemento(memento);
	origin.PrintState();
	delete memento;

	std::cout << ">>> Whole Pattern was terminated...\n";
}
