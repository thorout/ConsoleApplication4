#pragma once
#include <iostream>


class ComponentBase
{
public:
	virtual ~ComponentBase() { }
	virtual void Operation() = 0;
};


class ConcreteComponent : public ComponentBase
{
public:
	void Operation() override { std::cout << "Concrete ComponentBase method." << std::endl; }
	void SomeComponentMethod() { std::cout << "Concrete ComponentBase method2." << std::endl; }
};

class DecoratorComponent : public ComponentBase
{
public:
	~DecoratorComponent()
	{
		delete component_;
	}
	explicit DecoratorComponent(ComponentBase* component) : component_(component) {	}
	void Operation() override { component_->Operation(); }
private:
	ComponentBase* component_;
};

class ConcreteDecoratorA : public DecoratorComponent
{
public:
	ConcreteDecoratorA(ComponentBase* component) : DecoratorComponent(component) { }
	void Operation() override
	{
		std::cout << "Concrete Decorator A Operation." << std::endl;
		DecoratorComponent::Operation();
	}
};

class ConcreteDecoratorB : public DecoratorComponent
{
public:
	ConcreteDecoratorB(ComponentBase* component) : DecoratorComponent(component) { }
	void Operation() override
	{
		std::cout << "Concrete Decorator B Operation." << std::endl;
		DecoratorComponent::Operation();
	}
};




class Decorator
{
public:
	Decorator();
	~Decorator();
	void run();
};

