#pragma once
#include <iostream>
#include <memory>

class IStrategy
{
public:
	virtual ~IStrategy()
	{
	}

	virtual void AlgorithmInterface() = 0;

private:

};

class ConcreteStrategyA : public IStrategy
{
public:
	void AlgorithmInterface() override
	{
		std::cout << "Here is the action A." << std::endl;
	}

private:

};

class ConcreteStrategyB : public IStrategy
{
public:
	void AlgorithmInterface() override
	{
		std::cout << "Here is the action B." << std::endl;
	}

private:

};



class StrategyContext
{
public:
	void ContextInterface()
	{
		strategy_->AlgorithmInterface();
	}

	void SetStrategy(std::shared_ptr<IStrategy> strategy)
	{
		strategy_ = strategy;
	}

private:
	std::shared_ptr<IStrategy> strategy_;
};



class Strategy
{
public:
	Strategy();
	~Strategy();
	void run();
};

