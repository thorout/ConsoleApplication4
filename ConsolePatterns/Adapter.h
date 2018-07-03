#pragma once
#include <iostream>

class LibInterface
{
public:

	virtual ~LibInterface()
	{
	}

	void libMethod01()
	{
		std::cout << "LIB-Method01" << std::endl;
	}

	void libMethod02()
	{
		std::cout << "LIB-Method02" << std::endl;
	}

};


class NativeInterface
{
public:

	virtual ~NativeInterface()
	{
	}

	virtual void nativeMethod01() = 0;
	virtual void nativeMethod02() = 0;

};



class AdapterClass : public NativeInterface, public LibInterface
{
public:
	void nativeMethod01() override
	{
		libMethod02();
	}

	void nativeMethod02() override
	{
		libMethod02();
	}
};



class Adapter
{
public:
	Adapter();
	~Adapter();
	void run();
};


