#include "Mediator.h"



Mediator::Mediator()
{
	std::cout << "Pattern \"Command\"\n";
}


Mediator::~Mediator()
{
}


void ConcreteMediator::WidgetChanged(IColleague* widget)
{
	if (widget->getStatus())
	{
		dynamic_cast<ConcreteColleagueB*>(widget)->SetVisible();
	}
}



void Mediator::run()
{
	IMediator* mediator = new ConcreteMediator();
	IColleague* widgetA = new ConcreteColleagueA(mediator);
	IColleague* widgetB = new ConcreteColleagueB(mediator);
	dynamic_cast<ConcreteColleagueA*>(widgetA)->CheckIn();

	delete widgetB;
	delete widgetA;
	delete mediator;
	std::cout << ">>> Whole Pattern was terminated...\n";
}
