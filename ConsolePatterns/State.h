#pragma once
#include <iostream>
#include <set>


class IState
{
public:
	virtual ~IState()
	{
		std::cout << "~IState()" << std::endl;
	}

	virtual void Handle01() = 0;
	virtual void Handle02() = 0;
};

class ConcreteStateA : public IState
{ 
public:
	void Handle01() override
	{
		std::cout << "Operation > 01 < in state A." << std::endl;
	}

	void Handle02() override
	{
		std::cout << "Operation > 02 < in state A." << std::endl;
	}

};

class ConcreteStateB : public IState
{
public:
	void Handle01() override
	{
		std::cout << "Operation > 01 < in state B." << std::endl;
	}

	void Handle02() override
	{
		std::cout << "Operation > 02 < in state B." << std::endl;
	}
};



class Context
{
public:
	Context()
	{
		states_.insert(new ConcreteStateA);
		states_.insert(new ConcreteStateB);
		states_iterator = states_.begin();
	}

	~Context()
	{
		for (auto state : states_) delete state;
	}

	void NextState()
	{
		if (++states_iterator == states_.end())
			states_iterator = states_.begin();
		std::cout << "State is changed" << std::endl;
	}

	void Handle01()
	{
		(*states_iterator)->Handle01();
	}

	void Handle02()
	{
		(*states_iterator)->Handle02();
	}

private:
	std::set<IState*>::iterator states_iterator;
	std::set<IState*> states_;
};


class State
{
public:
	State();
	~State();
	void run();
};

