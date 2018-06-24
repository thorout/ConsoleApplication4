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
	PrototypeChild01();
	~PrototypeChild01();
	PrototypeBase* clone() override;
};

