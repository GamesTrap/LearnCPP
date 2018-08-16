#include "PersonnelAdministration.h"

#include <fstream>
#include <iostream>

PersonnelAdministration::PersonnelAdministration(const std::string& filename)
{
	std::ifstream data(filename);
	while(data)
	{
		std::string line;
		std::getline(data, line);
		if (line == "#") //End identifier found
			break;
		std::string name = line;
		std::getline(data, line);
		//line contains the personnel number
		m_personnel.emplace_back(name, line);
	}
	data.close();
}

void PersonnelAdministration::output() const
{
	if (m_personnel.empty())
		std::cout << "No data available!" << '\n';
	else
		for (const auto& person : m_personnel)
			std::cout << person.getName() << '\t' << person.getPersonnelNumber() << '\n';
}

void PersonnelAdministration::dialog() const
{
	while(true)
	{
		std::cout << "Personnel Number (X = End): ";
		std::string wantedPersonnelNo;
		std::cin >> wantedPersonnelNo;
		if (wantedPersonnelNo == "X" || wantedPersonnelNo == "x")
			break;
		bool found = false;
		for(const auto& person : m_personnel)
			if(wantedPersonnelNo == person.getPersonnelNumber())
			{
				std::cout << person.getName() << " found." << '\n';
				found = true;
				break;
			}
		if(!found)
		{
			std::cout << "not found!" << '\n';
		}
	}
}
