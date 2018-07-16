#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

class IObserver
{
public:
	IObserver()
	{
	}

	virtual ~IObserver()
	{
	}

	virtual void Update() = 0;

private:

};


class ISubject
{
public:
	ISubject()
	{
	}

	virtual ~ISubject()
	{
	}

	void Attach(IObserver* observer)
	{
		observers.push_back(observer);
	}

	void Dettach(IObserver* observer)
	{

		auto iterator = std::find(observers.begin(), observers.end(), observer);
		if (iterator != observers.end())
		{
			observers.erase(iterator);
		}
	}

	void Notify()
	{
		for (auto observer : observers)
		{
			observer->Update();
		}
	}

private:
	std::vector<IObserver*> observers;
};


class ConcreteSubject : public ISubject
{
public:
	ConcreteSubject()
	{
	}

	~ConcreteSubject()
	{
	}

private:

};

class ConcreteObserverA : public IObserver
{
public:
	ConcreteObserverA()
	{
	}

	~ConcreteObserverA()
	{
	}
	void Update() override
	{
		std::cout << "ConcreteObserverA: \"I've received a message.\"" << std::endl;	
	}

private:

};

class ConcreteObserverB : public IObserver
{
public:
	ConcreteObserverB()
	{
	}

	~ConcreteObserverB()
	{
	}

	void Update() override
	{
		std::cout << "ConcreteObserverB: \"I've received a message.\"" << std::endl;
	}

private:

};

class ConcreteObserverC : public IObserver
{
public:
	ConcreteObserverC()
	{
	}

	~ConcreteObserverC()
	{
	}

	void Update() override
	{
		std::cout << "ConcreteObserverC: \"I've received a message.\"" << std::endl;
	}

private:

};


class Observer
{
public:
	Observer();
	~Observer();
	void run();
};

