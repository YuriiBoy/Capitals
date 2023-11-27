#pragma once

class DataManager
{
	std::map<std::string, std::string> caps;
public:
	void loadData();
	void savedata();
	void displayData() const;
	void searchCapital();
	void addCapital();
	void correctCapital();
	void delCapital();
};

