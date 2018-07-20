#pragma once
#include <iostream>

class AbstractClass
{
public:
	virtual ~AbstractClass()
	{

	}
	void TemplateMethodRun() //Complex algorithm realisation
	{
		PrimitiveOperation01();
		PrimitiveOperation02();
		PrimitiveOperation03();
		PrimitiveOperation04();
	}

	virtual void PrimitiveOperation01() = 0;
	virtual void PrimitiveOperation02() = 0;
	virtual void PrimitiveOperation03() = 0;
	virtual void PrimitiveOperation04()
	{
		std::cout << "Operation 04 is executed." << std::endl;
	}
};

class ConcreteClass : public AbstractClass
{
public:
	void PrimitiveOperation01() override { std::cout << "Operation 01 is executed." << std::endl; }
	void PrimitiveOperation02() override { std::cout << "Operation 02 is executed." << std::endl; }
	void PrimitiveOperation03() override { std::cout << "Operation 03 is executed." << std::endl; }
};



class TemplateMethod
{
public:
	TemplateMethod();
	~TemplateMethod();
	void run();
};

