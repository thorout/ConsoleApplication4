#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

class ISubject;

struct SubjectState
{
	int someData01;
	int someData02;
	int someData03;
};

class IObserver
{
public:
	IObserver()
	{
	}

	virtual ~IObserver()
	{
	}

	virtual void Update(ISubject* observer) = 0;

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
			observer->Update(this);
		}
	}

	virtual const SubjectState& GetState() = 0;

private:
	std::vector<IObserver*> observers;
};


class ConcreteSubject : public ISubject
{
public:
	ConcreteSubject() 
	{
		std::cout << "ConcreteSubject() started." << std::endl;
		state_.someData01 = 1;
		state_.someData02 = 2;
		state_.someData03 = 3;
	}

	~ConcreteSubject()
	{
	}

	const SubjectState& GetState() override
	{
		return state_;
	}

	void SetState(const SubjectState& state)
	{
		state_ = state;
		Notify();
	}

private:
	SubjectState state_;
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
	void Update(ISubject* observer) override
	{
		SubjectState state = observer->GetState();
		std::cout << "ConcreteObserverA: \"I've notified >> \"" << state.someData01 << " " << state.someData02 << " " << state.someData03 << " " << std::endl;
	}

private:
	IObserver* observer_;
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

	void Update(ISubject* observer) override
	{
		SubjectState state = observer->GetState();
		std::cout << "ConcreteObserverB: \"I've notified >> \"" << state.someData01 << " " << state.someData02 << " " << state.someData03 << " " << std::endl;
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

	void Update(ISubject* observer) override
	{
		SubjectState state = observer->GetState();
		std::cout << "ConcreteObserverC: \"I've notified >> \"" << state.someData01 << " " << state.someData02 << " " << state.someData03 << " " << std::endl;
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

