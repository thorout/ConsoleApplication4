#include "ChainOfResponsibility.h"



ChainOfResponsibility::ChainOfResponsibility()
{
	std::cout << "Pattern \"Chain of Responsibility\"\n";
}


ChainOfResponsibility::~ChainOfResponsibility()
{
}


void ChainOfResponsibility::run()
{
	ConceteHandlerA chA01(nullptr);
	ConceteHandlerA chA02(&chA01);
	ConceteHandlerA chA03(&chA02);
	ConceteHandlerA chA04(&chA03);

	chA04.HandleRequest();

	std::cout << ">>> Whole Pattern was terminated...\n";
}
