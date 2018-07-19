#include "Strategy.h"



Strategy::Strategy()
{
	std::cout << "Pattern \"Strategy\"\n";
}


Strategy::~Strategy()
{
}


void Strategy::run()
{
	StrategyContext strategy_context{};

	strategy_context.SetStrategy(std::dynamic_pointer_cast<IStrategy>(std::make_shared<ConcreteStrategyA>()));
	strategy_context.ContextInterface();

	strategy_context.SetStrategy(std::make_shared<ConcreteStrategyB>());
	strategy_context.ContextInterface();

	std::cout << ">>> Whole Pattern was terminated...\n";
}
