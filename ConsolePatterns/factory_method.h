#pragma once

struct AbstractProduct
{
	~AbstractProduct() {}
	virtual void method() = 0;
};

struct ConcreteProductA : AbstractProduct
{
	void method() override { std::cout << "Product A method\n"; };
};

struct ConcreteProductB : AbstractProduct
{
	void method() override { std::cout << "Product B method\n"; };
};

struct ConcreteProductC : AbstractProduct
{
	void method() override { std::cout << "Product C method\n"; };
};

struct AbstractFactory
{
	virtual void Build() = 0;
	~AbstractFactory() {}
};


struct ConcreteFactoryA : AbstractFactory
{
	void Build() {}
};

//-----------------------------------------------------------

struct FactoryMethod
{
	void run() 
	{
		std::cout << "Factory Method pattern\n";
	}
};