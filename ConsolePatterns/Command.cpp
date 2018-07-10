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
	ICommand* command = new ConcreteCommandA(&doc);
	Menu menu;
	menu.SetCommand(command);
	menu.Click();
	std::cout << ">>> Whole Pattern was terminated...\n";
}
