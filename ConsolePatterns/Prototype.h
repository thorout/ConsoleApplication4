#pragma once
class Prototype
{
public:
	Prototype();
	virtual ~Prototype();
	void run();
};

class PrototypeBase
{

public:
	PrototypeBase();
	virtual ~PrototypeBase();
	virtual PrototypeBase* clone() = 0;
};

class PrototypeChild01 :
	public PrototypeBase
{
public:
	int some_parameter01;
	PrototypeChild01();
	~PrototypeChild01();
	PrototypeBase* clone() override;
};

class PrototypeChild02 :
	public PrototypeBase
{
public:
	int some_parameter02;
	int some_parameter22;
	PrototypeChild02();
	~PrototypeChild02();
	PrototypeBase* clone() override;
};

