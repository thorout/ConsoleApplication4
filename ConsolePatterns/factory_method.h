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
	virtual AbstractProduct* BuildProduct() = 0;
	~AbstractFactory() {}
};


struct ConcreteFactoryA : AbstractFactory
{
	AbstractProduct* BuildProduct() { return new ConcreteProductA; }
};

struct ConcreteFactoryB : AbstractFactory
{
	AbstractProduct* BuildProduct() { return new ConcreteProductB; }
};

struct ConcreteFactoryC : AbstractFactory
{
	AbstractProduct* BuildProduct() { return new ConcreteProductC; }
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


		//Unchanged area ======
		std::shared_ptr<AbstractProduct> product(factory->BuildProduct());
		product->method();
		//Unchanged area ======


	}
}; 

