#pragma once
#include <iostream>

class Document
{
public:
	void SomeAction()
	{
		std::cout << "Document : Doing some action!" << std::endl;
	}
};


class ICommand
{
public:
	virtual ~ICommand() { }
	virtual void execute() = 0;
};

class ConcreteCommandA : public ICommand
{
public:
	ConcreteCommandA(Document* doc) : document_(doc) { }

	void execute() override
	{
		std::cout << "Command is Executed..." << std::endl;
		document_->SomeAction();
	}
private:
	Document* document_;
};

class Menu
{
public:
	void SetCommand(ICommand* command) { command_ = command; }
	void Click() 
	{
		std::cout << "Menu is clicked..." << std::endl;
		command_->execute(); 
	}
private:
	ICommand* command_;
};


class Command
{
public:
	Command();
	~Command();
	void run();
};

