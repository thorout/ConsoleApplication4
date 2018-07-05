#include "Composite.h"
///#include <iomanip>
#include <vector>
#include <algorithm>

class Component
{
public:
	virtual ~Component() {}
	virtual void add(Component* comp) = 0;
	virtual void remove(Component* comp) = 0;
	virtual Component* getChild(int i) = 0;
	virtual void printName() = 0;
};

class Leaf : public Component
{
public:
	virtual ~Leaf()	{ }
	virtual void add(Component* comp) override { throw std::exception("Not supported method\n"); }
	virtual void remove(Component* comp) override { throw std::exception("Not supported method\n"); }
	virtual Component* getChild(int i) override { throw std::exception("Not supported method\n"); }
	virtual void printName() override { std::cout << this->name;  }
private:
	static int counter;
	std::string name = "leaf" + std::to_string(counter++) + "\n";
};

int Leaf::counter = 0;

class CompositeClass : public Component
{
public:
	virtual ~CompositeClass() {	}
	virtual void add(Component* comp) override { leafs.push_back(comp); }
	virtual void remove(Component* comp) override 
	{
		auto it = std::find(leafs.begin(), leafs.end(), comp);
		if (it != leafs.end()) 
		{
			delete *it;
			leafs.erase(it);
		}
	}
	virtual Component* getChild(int i) override { return leafs.at(i); }
	virtual void printName() override 
	{
		std::cout << ">>>> Composite:\n";
		for (auto leaf : leafs) leaf->printName();
	}
private:
	std::vector<Component*> leafs;
};


Composite::Composite()
{
	std::cout << "Pattern \"Composite\"\n";
}


Composite::~Composite()
{
}


void Composite::run()
{
	Component* root = new CompositeClass;

	for (size_t i = 0; i < 10; i++)
	{
		root->add(new Leaf);
	}

	Component* root2 = new CompositeClass;
	root->add(root2);

	for (size_t i = 0; i < 10; i++)
	{
		root2->add(new Leaf);
	}

	root->printName();

	try
	{
		root2->getChild(0)->getChild(0);
	}
	catch (const std::exception& e)
	{
		std::cout << "E R R O R ! >>>> " << e.what();
	}

	delete root;
	std::cout << ">>> Whole Pattern was terminated...\n";
}
