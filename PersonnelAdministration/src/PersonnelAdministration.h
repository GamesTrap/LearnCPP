#pragma once

#include <vector>
#include "Person.h"

class PersonnelAdministration
{
public:
	explicit PersonnelAdministration(const std::string& filename);

	void output() const;

	void dialog() const;

private:
	std::vector<Person> m_personnel;
};