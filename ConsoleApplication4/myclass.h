#pragma once
#include <iostream>

class IMyClass
{
public:
	virtual ~IMyClass() {};
	virtual int someAction() { data_ = 15; return data_; };
private:
	int data_ = 0;
};




