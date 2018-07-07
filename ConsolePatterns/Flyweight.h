#pragma once
#include <iostream>

class MassObject
{
public:
	MassObject(int number) : number_(number) { }
	int GetData() { return number_; }
private:
	int number_;
};


class IFlyweight
{
public:
	virtual ~IFlyweight() { }
	virtual void draw(MassObject& massObject) = 0;
};


class ConcreteFlyweight : public IFlyweight
{
public:
	ConcreteFlyweight(char c) : bigData_(c) { }
	virtual ~ConcreteFlyweight() { }
	void draw(MassObject& massObject) override { std::cout << bigData_ << massObject.GetData(); }
private:
	char bigData_;
};


class Flyweight
{
public:
	Flyweight();
	~Flyweight();
	void run();
};

