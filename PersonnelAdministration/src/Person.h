#pragma once
#include <string>
#include <utility>

class Person
{
public:
	Person(std::string name, std::string personnelNumber)
		: m_name{std::move(name)}, m_personnelNumber{std::move(personnelNumber)}
	{}

	const auto& getName() const { return m_name; }
	const auto& getPersonnelNumber() const { return m_personnelNumber; }

private:
	std::string m_name;
	std::string m_personnelNumber;
};
