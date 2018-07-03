#pragma once
#include <iostream>

class NativeInterface
{
public:

	NativeInterface()
	{
	}

	virtual ~NativeInterface()
	{
	}

	void nativeMethod01()
	{
		std::cout << "NATIVE-Method01" << std::endl;
	}

	void nativeMethod02()
	{
		std::cout << "NATIVE-Method02" << std::endl;
	}
};

