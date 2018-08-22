#include "NumObj.h"

#include <iostream>
#include <cassert>

//Initialization and definition of class-specific variables:
int NumberedObject::m_amo = 0;
unsigned long NumberedObject::m_maxNumber = 0L;
bool NumberedObject::testMode = false;

//Default constructor
NumberedObject::NumberedObject()
	: m_serialNo{ ++m_maxNumber }
{
	++m_amo;
	if(testMode)
	{
		if (m_serialNo == 1)
			std::cout << "Start of object creation!" << '\n';
		std::cout << "Object No. " << m_serialNo << " generated" << '\n';
	}
}

//Copy constructor
NumberedObject::NumberedObject(const NumberedObject& nobj)
	: m_serialNo{ ++m_maxNumber }
{
	++m_amo;
	if (testMode)
		std::cout << "Object No. " << m_serialNo << " with No. " << nobj.serialNumber() << " initialized" << '\n';
}

//Destructor
NumberedObject::~NumberedObject()
{
	m_amo--;
	if (testMode)
	{
		std::cout << "Object No. " << m_serialNo << " deleted" << '\n';

		if (m_amo == 0)
			std::cout << "last object deleted!" << '\n';
		if (m_amo < 0)
			std::cout << "ERROR! too often called delete!" << '\n';
	}
	else
		assert(m_amo >= 0);
}

unsigned long NumberedObject::serialNumber() const
{
	return m_serialNo;
}

int NumberedObject::amount()
{
	return m_amo;
}