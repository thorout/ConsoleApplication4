// ConsolePatterns.cpp : Defines the entry point for the console application.
//

#include "C:\Program Files (x86)\Visual Leak Detector\include\vld.h"
#include "stdafx.h"
#include <iostream>
#include <memory>
#include "factory_method.h"
#include "Prototype.h"
#include "Builder.h"
#include "Adapter.h"
#include "Bridge.h"
#include "Composite.h"
#include "Decorator.h"
#include "Flyweight.h"
#include "Proxy.h"
#include "ChainOfResponsibility.h"
#include "Command.h"
#include "Mediator.h"
#include "Memento.h"
#include "Observer.h"
#include "State.h"
#include "Strategy.h"
#include "TemplateMethod.h"

using std::cout;

int main()
{
	std::cout << "Hello\n";

	cout << "============================================================================================\n";
	FactoryMethod fm;
	fm.run(2);
	cout << "============================================================================================\n";

	cout << "============================================================================================\n";
	Prototype pr;
	pr.run();
	cout << "============================================================================================\n";

	cout << "============================================================================================\n";
	Builder br;
	br.run();
	cout << "============================================================================================\n";

	cout << "============================================================================================\n";
	Adapter adapter;
	adapter.run();
	cout << "============================================================================================\n";

	cout << "============================================================================================\n";
	Bridge bridge;
	bridge.run();
	cout << "============================================================================================\n";

	cout << "============================================================================================\n";
	Composite composite;
	composite.run();
	cout << "============================================================================================\n";

	cout << "============================================================================================\n";
	Decorator decorator;
	decorator.run();
	cout << "============================================================================================\n";

	cout << "============================================================================================\n";
	Flyweight flyweight;
	flyweight.run();
	cout << "============================================================================================\n";

	cout << "============================================================================================\n";
	Proxy proxy;
	proxy.run();
	cout << "============================================================================================\n";

	cout << "============================================================================================\n";
	ChainOfResponsibility chainOfResponsibility;
	chainOfResponsibility.run();
	cout << "============================================================================================\n";

	cout << "============================================================================================\n";
	Command command;
	command.run();
	cout << "============================================================================================\n";

	cout << "============================================================================================\n";
	Mediator mediator;
	mediator.run();
	cout << "============================================================================================\n";

	cout << "============================================================================================\n";
	Memento memento;
	memento.run();
	cout << "============================================================================================\n";

	cout << "============================================================================================\n";
	Observer observer;
	observer.run();
	cout << "============================================================================================\n";

	cout << "============================================================================================\n";
	State state;
	state.run();
	cout << "============================================================================================\n";

	cout << "============================================================================================\n";
	Strategy strategy;
	strategy.run();
	cout << "============================================================================================\n";

	cout << "============================================================================================\n";
	TemplateMethod template_method;
	template_method.run();
	cout << "============================================================================================\n";

	return 0;
}

