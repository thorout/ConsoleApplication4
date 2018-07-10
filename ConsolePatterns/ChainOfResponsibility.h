#pragma once
#include <iostream>


class Handler
{
public:
	Handler(Handler* h) : handler_(h) {	}
	virtual ~Handler() { }
	virtual void HandleRequest() 
	{
		if (handler_)
		{
			std::cout << "Handle to another handller" << std::endl;
			handler_->HandleRequest();
		}
		else
		{
			std::cout << "There is no handlers..." << std::endl;
		}
	}
private:
	Handler* handler_;

};

class ConceteHandlerA : public Handler
{
public:
	ConceteHandlerA(Handler* h) : Handler(h)
	{
	}
};



class ChainOfResponsibility
{
public:
	ChainOfResponsibility();
	~ChainOfResponsibility();
	void run();
};

