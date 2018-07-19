#include "Command.h"




Command::Command()
{
	std::cout << "Pattern \"Command\"\n";
}


Command::~Command()
{
}


void Command::run()
{
	Document doc;
	doc.SetText("Initial TEXT.");
	ICommand* command = new ConcreteCommandA(&doc);
	Menu menu;
	menu.SetCommand(command);

	History<ICommand> history;

	std::cout << " >>> " << doc.GetText() << std::endl;
	menu.Click();
	history.Push(command);
	delete command;
	std::cout << " >>> " << doc.GetText() << std::endl;
	//command->unexecute();
	command = history.Pop();
	command->unexecute();
	std::cout << " >>> " << doc.GetText() << std::endl;
	delete command;

	std::cout << ">>> Whole Pattern was terminated...\n";
}
