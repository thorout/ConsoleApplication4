#include "State.h"



State::State()
{
	std::cout << "Pattern \"State\"\n";
}


State::~State()
{
}


void State::run()
{
	Context* context = new Context;

	context->Handle01();
	context->Handle02();
	context->NextState();
	context->Handle01();
	context->Handle02();
	context->NextState();
	context->Handle01();
	context->Handle02();

	delete context;

	std::cout << ">>> Whole Pattern was terminated...\n";
}
