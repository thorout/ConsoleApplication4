#pragma once
#include <iostream>
#include <tuple>

class ConcreteElementA;
class ConcreteElementB;

class IVisitor
{
public:
	IVisitor() { }
	virtual ~IVisitor() { }
	virtual void VisitConcreteElementA(ConcreteElementA*) = 0;
	virtual void VisitConcreteElementB(ConcreteElementB*) = 0;
};

class ConcreteVisitor01 : public IVisitor
{
public:
	void VisitConcreteElementA(ConcreteElementA* elementA) override;
	void VisitConcreteElementB(ConcreteElementB* elementB) override;
	std::tuple<int, int> GetCounters()
	{
		return std::make_tuple(elementsA_counter_, elementsB_counter_);
	}

private:
	int elementsA_counter_ = 0;
	int elementsB_counter_ = 0;
};

class ConcreteVisitor02 : public IVisitor
{
public:
	void VisitConcreteElementA(ConcreteElementA* elementA) override;
	void VisitConcreteElementB(ConcreteElementB* elementB) override;
	std::tuple<int, int> GetCounters()
	{
		return std::make_tuple(elementsA_counter_, elementsB_counter_);
	}

private:
	int elementsA_counter_ = 0;
	int elementsB_counter_ = 0;
};


class Element
{
public:
	virtual ~Element() { }

	virtual void Accept(IVisitor* visitor) = 0;

private:
};

class ConcreteElementA : public Element
{
public:
	void Accept(IVisitor* visitor) override
	{
		visitor->VisitConcreteElementA(this);
	}

	int OperationA()
	{
		return data_;
	}
private:
	int data_ = 11;
};

class ConcreteElementB : public Element
{
public:
	void Accept(IVisitor* visitor) override
	{
		visitor->VisitConcreteElementB(this);
	}

	int OperationB()
	{
		return data_;
	}
private:
	int data_ = 22;
};



class Visitor
{
public:
	Visitor();
	~Visitor();
	void run();
};

