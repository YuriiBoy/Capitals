#include "Header.h"
#include "DataManager.h"

int main()
{
	// 1
	auto dm = std::make_unique<DataManager>();
	dm->loadData();
	dm->displayData();
	dm->searchCapital();
	dm->addCapital();
	dm->correctCapital();
	dm->delCapital();


	// Fin
	std::cout << "\n Finish";   
}
