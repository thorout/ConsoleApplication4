#include "Decorator.h"
#include <memory>


Decorator::Decorator()
{
	std::cout << "Pattern \"Decoder\"\n";
}


Decorator::~Decorator()
{
}


void Decorator::run()
{
	ComponentBase* comp1 = new ConcreteComponent;
	comp1->Operation();
	comp1 = new ConcreteDecoratorA(new ConcreteDecoratorB(comp1));
	comp1->Operation();
	dynamic_cast<ConcreteComponent*>(comp1)->SomeComponentMethod();
	delete comp1;
	std::cout << ">>> Whole Pattern was terminated...\n";
}
