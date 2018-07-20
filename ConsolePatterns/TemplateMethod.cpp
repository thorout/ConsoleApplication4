#include "TemplateMethod.h"



TemplateMethod::TemplateMethod()
{
	std::cout << "Pattern \"Template Method\"\n";
}


TemplateMethod::~TemplateMethod()
{
}


void TemplateMethod::run()
{
	ConcreteClass concrete_class;

	concrete_class.TemplateMethodRun();

	std::cout << ">>> Whole Pattern was terminated...\n";
}
