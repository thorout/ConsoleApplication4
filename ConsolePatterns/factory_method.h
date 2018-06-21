#pragma once


namespace { int iii = 0; }

struct AbstractProduct
{
	~AbstractProduct() { std::cout << "product was deleted...\n"; }
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
	virtual AbstractProduct* FactoryMethod() = 0;
	~AbstractFactory() { std::cout << "factory was deleted...\n"; }
};


struct ConcreteFactoryA : AbstractFactory
{
	AbstractProduct* FactoryMethod() { return new ConcreteProductA; }	//Factory method
};

struct ConcreteFactoryB : AbstractFactory
{
	AbstractProduct* FactoryMethod() { return new ConcreteProductB; }	//Factory method
}; 

struct ConcreteFactoryC : AbstractFactory
{
	AbstractProduct* FactoryMethod() { return new ConcreteProductC; }	//Factory method
};

//-----------------------------------------------------------

struct FactoryMethod
{
	void run(int kind_of) 
	{
		std::cout << "Factory Method pattern\n";

		std::shared_ptr<AbstractFactory> factory;

		switch (kind_of) {
		case 1: factory = std::make_shared<ConcreteFactoryA>();
			break;
		case 2: factory = std::make_shared<ConcreteFactoryB>();
			break;
		case 3: factory = std::make_shared<ConcreteFactoryC>();
			break;
		}

		{
			//Unchanged area ======
			std::shared_ptr<AbstractProduct> product(factory->FactoryMethod());
			product->method();
			//Unchanged area ======
		}
		std::cout << "Program terminated...\n";

	}
}; 

