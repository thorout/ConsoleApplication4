#pragma once
#include <iostream>


class Component
{
public:
	virtual ~Component() { }
	virtual void Operation() = 0;
};


class ConcreteComponent : public Component
{
public:
	void Operation() override { std::cout << "Concrete Component method." << std::endl; }
	void SomeComponentMethod() { std::cout << "Concrete Component method2." << std::endl; }
};

class DecoratorComponent : public Component
{
public:
	explicit DecoratorComponent(Component* component) : component_(component) {	}
	void Operation() override { component_->Operation(); }
private:
	Component* component_;
};

class ConcreteDecoratorA : public DecoratorComponent
{
public:
	ConcreteDecoratorA(Component* component) : DecoratorComponent(component) { }
	void Operation() override
	{
		std::cout << "Concrete Decorator A Operation." << std::endl;
		DecoratorComponent::Operation();
	}
};

class ConcreteDecoratorB : public DecoratorComponent
{
public:
	ConcreteDecoratorB(Component* component) : DecoratorComponent(component) { }
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

