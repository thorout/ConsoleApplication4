#pragma once
#include <iostream>

class DataState
{
public:
	int data01_ = 1;
	int data02_ = 2;
};


class MementoClass
{
public:
	~MementoClass()
	{
		delete state_;
	}
private:
	friend class Originator;
	MementoClass()
	{
	}

	void SetState(DataState* state) 
	{
		state_ = new DataState(*state); 
	}
	DataState* GetState() 
	{
		return state_;
	}

	DataState* state_;
};


class Originator
{
public:
	Originator()
	{
		state_ = new DataState();
		state_->data01_ = 10;
		state_->data02_ = 20;
	}

	~Originator()
	{
		delete state_;
	}

	MementoClass* CreateMemento()
	{
		MementoClass* memento = new MementoClass;
		memento->SetState(state_);
		return memento;
	}

	void SetMemento(MementoClass* memento)
	{
		*state_ = *memento->GetState();
	}

	void PrintState()
	{
		std::cout << "Current state is: " << state_->data01_ << " " << state_->data02_ << std::endl;
	}

	void ChangeState()
	{
		state_->data01_ = 100;
		state_->data01_ = 200;
	}

private:
	DataState* state_;
};



class Memento
{
public:
	Memento();
	~Memento();
	void run();
};

