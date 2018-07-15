#pragma once
#include <iostream>
#include <memory>

class IColleague;

class IMediator
{
public:
	IMediator()
	{
	}

	virtual ~IMediator()
	{
	}

	virtual void WidgetChanged(IColleague* widget) = 0;

private:

};


class ConcreteMediator : public IMediator
{
public:
	ConcreteMediator()
	{
	}

	~ConcreteMediator()
	{
	}

	void WidgetChanged(IColleague* widget) override;

private:

};


class IColleague
{
public:
	explicit IColleague(IMediator* director) : director_(director)	{ }

	virtual ~IColleague() {	}

	virtual void Changed()
	{
		director_->WidgetChanged(this);
	}

	bool getStatus()
	{
		return status_;
	}

private:
	IMediator* director_;
protected:
	bool status_ = false;
};

class ConcreteColleagueA : public IColleague
{
public:
	ConcreteColleagueA(IMediator* director) : IColleague(director) { }
	void CheckIn()
	{
		std::cout << "WidgetA is checked in." << std::endl;
		status_ = true;
		Changed();
	}
private:

};

class ConcreteColleagueB : public IColleague
{
public:
	ConcreteColleagueB(IMediator* director) : IColleague(director) { }
	void SetVisible() 
	{
		std::cout << "WidgetB is visible." << std::endl;
	}
};



class Mediator
{
public:
	Mediator();
	~Mediator();
	void run();
};

