#include "Flyweight.h"
#include <vector>
#include <unordered_map>



Flyweight::Flyweight()
{
	std::cout << "Pattern \"Flyweight\"\n";
}


Flyweight::~Flyweight()
{
}


void Flyweight::run()
{
	std::vector<MassObject> vMo{ 100,200,300,400,500,600,700,800,900,1000,1100,1200 };

	std::unordered_map<int, IFlyweight*> flyweights;
	auto cf = ConcreteFlyweight('A');
	flyweights.insert(std::make_pair(1, &cf));

	auto it = flyweights.find(1);
	if (it != flyweights.end())
	{
		try
		{
			auto pflyw = it->second;
			pflyw->draw(vMo.at(1));
			pflyw->draw(vMo.at(2));
			pflyw->draw(vMo.at(7));
		}
		catch (const std::exception& e)
		{
			std::cerr << e.what();
		}
	}
	std::cout << ">>> Whole Pattern was terminated...\n";

}
