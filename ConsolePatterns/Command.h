#pragma once
#include <iostream>
#include <string>
#include <stack>
#include <memory>

template <class T>
class History
{
public:
	void Push(T* command)
	{
		history_.push(command->Clone());
	}

	T* Pop()
	{
		T* copy = history_.top();
		history_.pop();
		return copy;
	}

private:
	std::stack<T*> history_;
};


class Document
{
public:
	void SomeAction()
	{
		std::cout << "Document : Doing some action!" << std::endl;
		text_ = "Some text after command implementation.";
	}
	void SetText(std::string t)
	{
		text_ = t;
	}
	std::string GetText()
	{
		return text_;
	}

private:
	std::string text_ = "";
};


class ICommand
{
public:
	virtual ~ICommand() { }
	virtual void execute() = 0;
	virtual void unexecute() = 0;
	virtual ICommand* Clone() = 0;
};



class ConcreteCommandA : public ICommand
{
public:
	ConcreteCommandA(Document* doc) : document_(doc) { }

	void execute() override
	{
		std::cout << "Command is Executed..." << std::endl;
		Backup();
		document_->SomeAction();

	}
	void unexecute() override
	{
		std::cout << "Command is Unexecuted... Restore document state.." << std::endl;
		document_->SetText(backup_);
	}

	ICommand* Clone() override
	{
		return new ConcreteCommandA(*this);
	}

private:
	void Backup() { backup_ = document_->GetText(); }
	Document* document_;
	std::string backup_;
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

