#include "Visitor.h"
#include <vector>
#include <stdlib.h>
#include <time.h>

Visitor::Visitor()
{
	std::cout << "Pattern \"Visitor\"\n";
}


Visitor::~Visitor()
{
}




inline void ConcreteVisitor01::VisitConcreteElementA(ConcreteElementA * elementA)
{
	elementsA_counter_++;
	std::cout << "Concrete Visitor 01 for Element A is run. Element data is equal " << elementA->OperationA() << ". Counter of processed elements is " << elementsA_counter_ << std::endl;
}

inline void ConcreteVisitor01::VisitConcreteElementB(ConcreteElementB * elementB)
{
	elementsB_counter_++;
	std::cout << "Concrete Visitor 01 for Element B is run. Element data is equal " << elementB->OperationB() << ". Counter of processed elements is " << elementsB_counter_ << std::endl;
}

inline void ConcreteVisitor02::VisitConcreteElementA(ConcreteElementA * elementA)
{
	elementsA_counter_++;
	std::cout << "Concrete Visitor 02 for Element A is run. Element data is equal " << elementA->OperationA() << ". Counter of processed elements is " << elementsA_counter_ << std::endl;
}

inline void ConcreteVisitor02::VisitConcreteElementB(ConcreteElementB * elementB)
{
	elementsB_counter_++;
	std::cout << "Concrete Visitor 02 for Element B is run. Element data is equal " << elementB->OperationB() << ". Counter of processed elements is " << elementsB_counter_ << std::endl;
}




void Visitor::run()
{
	std::vector<Element*> vector_of_elements;

	srand(time(NULL));
	for (size_t i = 0; i < 10; i++)
	{
		int r = rand() / (RAND_MAX / 2); //r is random value [0..1]
		if (r)
		{
			vector_of_elements.push_back(new ConcreteElementA);
		}
		else
		{
			vector_of_elements.push_back(new ConcreteElementB);
		}
	}

	ConcreteVisitor01 visitor01;
	ConcreteVisitor02 visitor02;

	for (auto element : vector_of_elements) element->Accept(&visitor01);
	for (auto element : vector_of_elements) element->Accept(&visitor02);

	for (auto element : vector_of_elements) delete element;

	auto results01 = visitor01.GetCounters();
	std::cout << "Final visiter01 counters of element A is " << std::get<0>(results01) << std::endl;
	std::cout << "Final visiter01 counters of element B is " << std::get<1>(results01) << std::endl;

	auto results02 = visitor02.GetCounters();
	std::cout << "Final visiter02 counters of element A is " << std::get<0>(results02) << std::endl;
	std::cout << "Final visiter02 counters of element B is " << std::get<1>(results02) << std::endl;

	std::cout << ">>> Whole Pattern was terminated...\n";
}
