#include "Header.h"
#include "DataManager.h"

void DataManager::loadData()
{
	std::ifstream fin;
	fin.open("Capitals.txt");
	std::string country;
	std::string capital;
	// 
	while (!fin.eof()) 	{
		std::getline(fin, country);
		if (country != "") {
			std::getline(fin, capital);
			caps.insert({ country, capital });
		}
	}
	std::cout << "\n Data has been loaded";
	fin.close();
}

void DataManager::savedata()
{
	std::ofstream fout;
	fout.open("Capitals.txt");
	for (const auto& elem : caps) {
		fout << elem.first << std::endl;
		fout << elem.second << std::endl;
	}
	std::cout << "\n Data has been saved";
	fout.close();
}

void DataManager::displayData() const
{
	if (caps.empty()) {
		std::cout << "\n There are no any data\n";
	}
	else {
		std::cout << "\n Catalogue has " << caps.size() << " elements:\n";
		std::cout << " ==============================" << std::endl;
		for (const auto& elem : caps) {
			std::cout << " - " << elem.first;
			std::cout << " =>" << elem.second;
			std::cout << std::endl;
		}
	}
}

void DataManager::searchCapital()
{
	std::string country;
	std::cout << "\n Input name of the Country: ";
	std::getline(std::cin, country);
	auto iter = caps.find(country);
	if (iter == caps.end()) {
		std::cout << "\n This Country is not in the list.";
	}
	else {
		std::cout << " The capital of " << country << " is " << iter->second;
	}
}

void DataManager::addCapital()
{
	std::string country;
	std::string capital;
	std::cout << "\n Please input name of the Country you want to add- ";
	std::getline(std::cin, country);
	std::cout << "\n Please input name of the Capital - ";
	std::getline(std::cin, capital);
	caps.insert({ country, capital });
	savedata();
}

void DataManager::correctCapital()
{
	loadData();
	std::string country;
	std::string capital;
	char choice;
	std::cout << "\n Please input name of the Country information you want to correct - ";
	std::getline(std::cin, country);

	auto iter = caps.find(country);
	if (iter == caps.end()) {
		std::cout << "\n There is no such country in the list";
	}
	else {
		std::cout << " - " << country << " => " << iter->second;
		std::cout << "\n Do you want to correct country (y/n) ? - ";
		std::cin >> choice;
		if (choice == 'y') {
			std::cout << " Please write correct name of the country - ";
			std::cin.ignore();
			std::getline(std::cin, country);
			caps.insert({ country, iter->second });
			caps.erase(iter);
		}
		else {
			std::cout << " Please write correct capital name - ";
			std::cin.ignore();
			std::getline(std::cin, capital);
			country = iter->first;
			caps.erase(iter);
			caps.insert({ country , capital });
		}
	}
	savedata();
}

void DataManager::delCapital()
{
	std::string country;
	std::cout << "\n Please input name of the Country you want to delete - ";
	std::getline(std::cin, country);

	auto iter = caps.find(country);
	if (iter == caps.end()) {
		std::cout << "\n There is no such country in the list";
	}
	else {
		caps.erase(iter);
		std::cout << "\n Information of the country - " << country << " has been deleted\n";
	}
	savedata();
}
